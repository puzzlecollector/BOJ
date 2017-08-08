#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <algorithm> 
#include <vector> 
using namespace std;  

#define MAX 100001 
#define COLOR 18
#define INF 987654321

vector<int> tree[MAX];  
bool visited[MAX];  
int cache[MAX][COLOR];  

int coloring(int pos,int color){
	int &ret = cache[pos][color];  
	if (ret != -1) return ret;  
	visited[pos] = true;  
	ret = color;  
	for (int i = 0; i < tree[pos].size(); i++){
		if (visited[tree[pos][i]]) continue;  
		int choose = INF; 
		for (int j = 1; j <= 17; j++){
			// 만약에 인접해 있는 노드들이 현재 칠해져 있는 노드들과 색깔이 다르다면 
			// 색칠하고 choose를 갱신해준다.    
			if (j != color) choose = min(choose,coloring(tree[pos][i],j)); 
		}
		ret += choose;  
	}
	visited[pos] = false;  
	return ret; 
}

int main(){
	int n; 
	scanf("%d",&n);  
	for (int i = 0; i < n-1; i++){
		int a,b; 
		scanf("%d %d",&a,&b);  
		tree[a].push_back(b);  
		tree[b].push_back(a); 
	}
	memset(cache,-1,sizeof(cache)); 
	int ans = INF; 
	for (int i = 1; i <= 17; i++){
		ans = min(ans,coloring(1,i)); 
	}
	printf("%d\n",ans); 
	return 0;  
}

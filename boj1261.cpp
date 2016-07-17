#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <algorithm> 
#include <vector> 
#include <queue> 
#include <utility> 
#include <string> 
using namespace std;  

#define INF 987654321 
#define MAXM 101 
#define MAXN 101 

typedef pair<int,int> P;  
typedef pair<int,P> PP; // 최단거리, 위치
int G[MAXM][MAXN];  
int d[MAXM][MAXN];  
int dm[4] = {1,0,-1,0};  
int dn[4] = {0,1,0,-1}; 
int M,N;  

bool inRange(int y,int x){
	return (y >= 1 && y <= M && x >= 1 && x <= N);  
}

void dijkstra(P start){
	for (int i = 1; i <= M; i++){
		for (int j = 1; j <= N; j++){
			d[i][j] = INF; 
		}
	}
	priority_queue< PP,vector<PP>,greater<PP> > que;  
	d[start.first][start.second] = G[start.first][start.second]; 
	que.push(PP(d[start.first][start.second],start)); 
	while (!que.empty()){
		PP pp = que.top(); que.pop(); 
		P v = pp.second;  
		if (d[v.first][v.second] < pp.first) continue;  
		for (int i = 0; i < 4; i++){
			int nm = v.first+dm[i]; 
			int nn = v.second+dn[i]; 
			if (inRange(nm,nn) && d[nm][nn] > d[v.first][v.second]+G[nm][nn]){
				d[nm][nn] = d[v.first][v.second]+G[nm][nn]; 
				que.push(PP(d[nm][nn],P(nm,nn)));  
			}
		}
	}
}

int main(){
	scanf("%d %d",&M,&N);  
	swap(M,N); // 세로를 M, 가로를 N으로 착각하고 코딩을 한 결과... 모든걸 수정하기 귀찮아서 M,N을 뒤바꿔줌. 
	for (int i = 1; i <= M; i++){
		char input[N+1]; 
		scanf("%s",input); 
		for (int j = 1; j <= N; j++){
			G[i][j] = (input[j-1] == '0' ? 0 : 1); 
		}
	}
	dijkstra(P(1,1));  
	printf("%d\n",d[M][N]);  
	return 0;  
}

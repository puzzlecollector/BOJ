#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <cstring> 
#include <algorithm> 
#include <queue> 
using namespace std;  
typedef pair<int,int> P; 
int visited[1000001];  
int parent[1000001]; // if we applied some operation on i to get j, we have parent[j] = i;   
vector<int> reconstruct(int x){
	vector<int> path; 
	for (;x != -1;x = parent[x]){
		path.push_back(x); 
	}
	reverse(path.begin(),path.end()); 
	return path;  
}
int main(){
	int n; 
	scanf("%d",&n); 
	queue<P> q; 
	q.push(P(n,0)); 
	visited[n] = 1; 
	memset(parent,-1,sizeof(parent));   
	while (!q.empty()){
		P p = q.front(); q.pop(); 
		if (p.first == 1){
			printf("%d\n",p.second); 
			break; 
		}
		int x = p.first; 
		int cnt = p.second; 
		if (x%3 == 0 && !visited[x/3]){
			visited[x/3] = 1; 
			q.push(P(x/3,cnt+1)); 
			parent[x/3] = x;  
		}
		if (x%2 == 0 && !visited[x/2]){
			visited[x/2] = 1;  
			q.push(P(x/2,cnt+1)); 
			parent[x/2] = x; 
		}
		if (x-1 >= 1 && !visited[x-1]){
			visited[x-1] = 1; 
			q.push(P(x-1,cnt+1));
			parent[x-1] = x;   
		}
	}
	// reconstruct our path 
	vector<int> ans = reconstruct(1);  
	for (int i = 0; i < ans.size(); i++){
		printf("%d ",ans[i]);  
	}
	printf("\n");  
	return 0;  	
}

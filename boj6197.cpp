#include <iostream> 
#include <cstdio> 
#include <vector> 
#include <queue> 
#include <algorithm>
using namespace std; 

#define MAXN 5001 
#define INF 987654321

typedef pair<int,int> P; // distance, node number. 

int N,R; 
struct edge {int to,cost;};  
vector<edge> G[MAXN];  
int dist[MAXN],dist2[MAXN];  

void solve(){
	priority_queue< P,vector<P>,greater<P> > que; 
	fill(dist,dist+N,INF); 
	fill(dist2,dist2+N,INF);  
	dist[0] = 0;  
	que.push(P(0,0));  
	while (!que.empty()){
		P p = que.top(); que.pop(); 
		int v = p.second, d = p.first;  
		if (dist2[v] < d) continue; 
		for (int i = 0; i < G[v].size(); i++){
			edge &e = G[v][i];  
			int d2 = d+e.cost; 
			if (dist[e.to] > d2){
				swap(dist[e.to],d2);  
				que.push(P(dist[e.to],e.to));  
			}
			if (dist2[e.to] > d2 && dist[e.to] < d2){
				dist2[e.to] = d2;  
				que.push(P(dist2[e.to],e.to));  
			}
		}
	}
	printf("%d\n",dist2[N-1]); 
}

int main(){
	scanf("%d %d",&N,&R);  
	for (int i = 0; i < R; i++){
		int A,B,D;
		scanf("%d %d %d",&A,&B,&D);  
		--A,--B; 
		edge e;
		e.to = B, e.cost = D;  
		G[A].push_back(e);  
		e.to = A, e.cost = D; 
		G[B].push_back(e);  
	}
	solve();  
	return 0; 
}

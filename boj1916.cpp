#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <queue> 
#include <vector> 
#include <utility> 
#include <algorithm>
using namespace std;

#define MAXV 5001
#define MAXE 10001 
#define INF 987654321

typedef pair<int,int> P; // min-distance, node number

struct edge{int to,cost;};   
vector<edge> G[MAXV];
int d[MAXV];     
int V,E;  

void dijkstra(int s){
	fill(d,d+V,INF);  
	d[s] = 0; 
	priority_queue< P, vector<P>, greater<P> > que; 
	que.push(P(d[s],s)); 
	while (!que.empty()){
		P p = que.top(); que.pop();  
		int v = p.second; 
		if (d[v] < p.first) continue; 
		for (int i = 0; i < G[v].size(); i++){
			edge e = G[v][i];  
			if (d[e.to] > d[v]+e.cost){
				d[e.to] = d[v]+e.cost;  
				que.push(P(d[e.to],e.to)); 
			}
		}
	}
}

int main(){
	scanf("%d",&V);  
	scanf("%d",&E);  
	for (int i = 0; i < E; i++){
		int a,b,c;  
		scanf("%d %d %d",&a,&b,&c); 
		--a,--b;  
		edge e; e.to = b, e.cost = c;  
		G[a].push_back(e);  
	}
	int start,goal; 
	scanf("%d %d",&start,&goal); 
	--start,--goal;  
	dijkstra(start); 
	printf("%d\n",d[goal]);  
	return 0;  
} 

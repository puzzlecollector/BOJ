// Note that we are using 0-based indexing. 
#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <algorithm> 
#include <queue> 
#include <vector>
#include <utility>
using namespace std; 

#define MAXV 111 
#define MAXE 222
#define INF 987654321 

struct edge {int to, cost; }; 
typedef pair<int,int> P; // min distance, node number  

vector<edge> G[MAXV]; 
int d[MAXV];  
int previous[MAXV]; 
int hire[MAXV];  
int V,E;  

void dijkstra(int s){
	for (int i = 0; i < V; i++){
		d[i] = INF; 
		previous[i] = -1; 
	}
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
				previous[e.to] = v;  
				que.push(P(d[e.to],e.to)); 
			}
		} 
	} 
}

vector<int> retrievePath(int t){
	vector<int> path; 
	for (; t != -1; t = previous[t]) path.push_back(t); 
	reverse(path.begin(),path.end()); 
	return path; 
}	

int main(){
	scanf("%d %d",&V,&E); 
	for (int i = 0; i < E; i++){
		int a,b; 
		scanf("%d %d",&a,&b);
		--a,--b;    
		edge e; 
		e.to = b, e.cost = 1; 
		G[a].push_back(e); 
	}
	vector<int> nodes1; 
	vector<int> nodes2; 
	dijkstra(0); 
	nodes1 = retrievePath(1);  
	dijkstra(1);  
	nodes2 = retrievePath(0);  
	for (int i = 0; i < nodes1.size(); i++){
		hire[nodes1[i]] = 1;  
	}
	for (int i = 0; i < nodes2.size(); i++){
		hire[nodes2[i]] = 1;  
	} 
	int cnt = 0; 
	for (int i = 0; i < V; i++){
		if (hire[i]) ++cnt; 
	}
	printf("%d\n",cnt); 
	return 0; 
}	

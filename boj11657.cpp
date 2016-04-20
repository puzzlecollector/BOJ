// implement bellman-ford in order to solve the time travelling problem. 
// first, we check if a negative cycle exists in the graph.  
#include <iostream> 
#include <cstdio> 
#include <cstring> 
#include <algorithm> 
#include <cstdlib> 
#include <vector> 
#include <utility> 
using namespace std; 

#define MAXV 501 
#define MAXE 6001
#define INF 987654321

struct edge{int from,to,cost;}; 
edge es[MAXE];   
int d1[MAXV];  // for detecting negative cycle. 
int d2[MAXV];  // for finding shortest path 
int V,E;   

void bellmanFord(int s){ // algorithm for bellman-ford: single source shortest path. 
	for (int i = 0; i < V; i++){
		d2[i] = INF;  
	}
	d2[s] = 0; 
	while (true){
		bool update = false; 
		for (int i = 0; i < E; i++){
			edge e = es[i];  
			if (d2[e.from] != INF && d2[e.to] > d2[e.from]+e.cost){
				d2[e.to] = d2[e.from]+e.cost;  
				update = true; 
			}
		}
		if (!update) break; 
	}
}

bool find_negative_cycle(){
	memset(d1,0,sizeof(d1)); 
	for (int i = 0; i < V; i++){
		for (int j = 0; j < E; j++){
			edge e = es[j];  
			if (d1[e.to] > d1[e.from]+e.cost){
				d1[e.to] = d1[e.from]+e.cost;  
				if (i == V-1) return true;  // negative cycle exists. 
			}
		}
	}
	return false;  
}

int main(){
	scanf("%d %d",&V,&E); 
	for (int i = 0; i < E; i++){
		int a,b,c;  
		scanf("%d %d %d",&a,&b,&c);  
		--a,--b;  
		edge e; 
		e.from = a, e.to = b, e.cost = c;  
		es[i] = e;  
	}
	if (find_negative_cycle()){
		// first check for negative cycle. 
		printf("%d\n",-1);  
	}else{
		bellmanFord(0);  
		for (int i = 1; i < V; i++){
			printf("%d\n",(d2[i] == INF) ? -1 : d2[i]);  
		}
	}
	return 0; 
}

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std; 

#define INF 987654321
int graph[401][401]; 

int main(){
	// initializing step
	for (int i = 0; i < 401; i++){
		for (int j = 0; j < 401; j++){
			graph[i][j] = INF; 
		}
	}
	int V,E; 
	scanf("%d %d",&V,&E); 
	for (int i = 0; i < E; i++){
		int a,b,c;  
		scanf("%d %d %d",&a,&b,&c); 
		--a,--b;  
		graph[a][b] = c; 
	}
	// floyd-warshall
	for (int k = 0; k < V; k++){
		for (int i = 0; i < V; i++){
			for (int j = 0; j < V; j++){
				graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]); 
			}
		}
	}
	// let's get length of minimum cycle 
	int minCycleLen = INF; 
	for (int i = 0; i < V; i++){
		minCycleLen = min(minCycleLen,graph[i][i]);  
	}
	printf("%d\n",(minCycleLen == INF ? -1 : minCycleLen));  
	return 0; 
}

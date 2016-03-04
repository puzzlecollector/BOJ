// Floyd Warshall for undirected graph (with no negative cycles)
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
using namespace std; 

#define INF 987654321
#define MAXV 101

int graph[MAXV][MAXV]; 

int main(){
	// initialize graph. 
	for (int i = 0; i < MAXV; i++){
		for (int j = 0; j < MAXV; j++){
			if (i != j) graph[i][j] = INF; 
		}
	}
	// get input 
	int N,M; 
	cin >> N >> M; 
	for (int i = 0; i < M; i++){
		int a,b; 
		cin >> a >> b; 
		--a,--b; 
		graph[a][b] = graph[b][a] = 1; 
	}
	// floyd warshall 
	for (int k = 0; k < N; k++){
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);  
			}
		}
	}
	// compute minimum "Kevin Bacon Number". 
	int minVal = INF, person; 
	for (int i = 0; i < N; i++){
		int sum = 0;  
		for (int j = 0; j < N; j++){
			if (graph[i][j] != INF) sum += graph[i][j];  
		}
		if (sum < minVal){
			minVal = sum; 
			person = i;  
		}
	}
	// output the person with the least "Kevin Bacon Number". 
	cout << person+1 << endl; // because we used zero-based indexing. 
	return 0;  
}

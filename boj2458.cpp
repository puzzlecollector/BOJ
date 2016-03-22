#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm> 
using namespace std;  

int graph[501][501]; 
#define INF 987654321 

int main(){
	for (int i = 0; i < 501; i++){
		for (int j = 0; j < 501; j++){
			if (i == j) graph[i][j] = 0; 
			else graph[i][j] = INF; 
		}
	}
	int N,M; 
	cin >> N >> M;  
	for (int i = 0; i < M; i++){
		int a,b; 
		cin >> a >> b; 
		--a,--b; 
		graph[a][b] = 1; 
	}
	// floyd-warshall 
	for (int k = 0; k < N; k++){
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				graph[i][j] = min(graph[i][j],graph[i][k]+graph[k][j]);  
			}
		}
	}
	// if there exists a path from i to j 
	// or from j to i
	int cnt = 0; 
	for (int i = 0; i < N; i++){
		bool flag = true; 
		for (int j = 0; j < N; j++){
			if (i == j) continue; 
			if (graph[i][j] == INF && graph[j][i] == INF){
				flag = false; 
				break; 
			}
		}
		if (flag) ++cnt; 
	}
	/*
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			if (graph[i][j] == INF) cout << "INF" << " ";
			else cout << graph[i][j] << " "; 
		} 
		cout << endl;
	}*/
	cout << cnt << endl; 
	return 0; 
}

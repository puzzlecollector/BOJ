#include <iostream>
#include <vector>
#include <cstring> 
#include <algorithm>
using namespace std; 

#define MAXV 20005

int color[MAXV]; // color using 1 or -1. 

bool dfs(vector<int> G[], int v, int c){
	color[v] = c; 
	for (int i = 0; i < G[v].size(); i++){
		if (color[G[v][i]] == c) return false; 
		else if (color[G[v][i]] == 0 && !dfs(G,G[v][i],-c)) return false;  
	}
	return true; 
}

void solve(vector<int> G[], int V){
	for (int i = 0; i < V; i++){
		if (color[i] == 0){
			if (!dfs(G,i,1)){
				cout << "NO" << endl;
				return; 
			}
		}
	}
	cout << "YES" << endl; 
}

int main(){
	int T; 
	cin >> T; 
	for (int i = 0; i < T; i++){
		int V,E;  
		memset(color,0,sizeof(color)); 
		cin >> V >> E; 
		vector<int> G[20001]; 
		for (int j = 0; j < E; j++){
			int a,b; 
			--a,--b;  
			cin >> a >> b; 
			G[a].push_back(b); 
			G[b].push_back(a); 
		}
		if (V == 1){
			cout << "NO" << endl;
			continue; 
		}else solve(G,V);
	}
	return 0; 
}

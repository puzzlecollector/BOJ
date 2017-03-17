// reconstructing graph with minimum number of edges 
// given the result of all pairs shortest pair distance from floyd-warshall algorithm. 
#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
using namespace std; 

#define INF 987654321

int adj[21][21]; 
int g[21][21];  

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	int V; 
	cin >> V; 
	for (int i = 1; i <= V; i++){
		for (int j = 1; j <= V; j++){
			cin >> adj[i][j]; 
			g[i][j] = adj[i][j];  
		}
	}
	for (int k = 1; k <= V; k++){
		for (int i = 1; i <= V; i++){
			for (int j = 1; j <= V; j++){
				if ((adj[i][j] == adj[i][k]+adj[k][j]) && (i != j) && (i != k) && (j != k)){
					//cout << "(" << i << "," << j << "," << k << ")" << endl; 
					//cout << adj[i][j] << " " << adj[i][k] << " " << adj[k][j] << endl; 
					g[i][j] = 0; 
				}	
			}
		}
	}
	int sum = 0; 
	for (int i = 1; i <= V; i++){
		for (int j = 1; j <= V; j++){
			sum += g[i][j]; 
		}
	}
	int ans = sum/2; // a->b, b->a 값이 똑같으므로 2번 등장, 따라서 2로 나눠야함. 
	// now let's first check if we get a different result from the original. 
	// adjusting graph g. 
	for (int i = 1; i <= V; i++){
		for (int j = 1; j <= V;j++){
			if ((i != j) && g[i][j] == 0) g[i][j] = INF;   
		}
	}
	// floyd on g. 
	for (int k = 1; k <= V; k++){
		for (int i = 1; i <= V; i++){
			for (int j = 1; j <= V; j++){
				g[i][j] = min(g[i][j],g[i][k]+g[k][j]);  
			}
		}
	}
	for (int i = 1; i <= V; i++){
		for (int j = 1; j <= V; j++){
			if (adj[i][j] != g[i][j]){
				// discrepancy!! 모순!! 
				cout << -1 << endl;
				return 0;  
			}
		}
	}
	cout << ans << endl; 
	return 0; 
}

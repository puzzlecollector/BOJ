#include <iostream>
#include <cstdlib>
#include <vector> 
#include <algorithm>
#include <climits> 
using namespace std;  

#define INF 987654321

int grid[101][101];  

int main(){
	int t; 
	cin >> t; 
	while (t--){ 
		// initialize grid 
		for (int i = 0; i < 101; i++){
			for (int j = 0; j < 101; j++){
				if (i == j) grid[i][j] = 0;  
				else grid[i][j] = INF;  
			}
		}
		// get input 
		int n,p,q; 
		cin >> n >> p >> q;  
		vector<int> v;  
		for (int i = 0; i < n; i++){
			int pos; 
			cin >> pos; 
			--pos; 
			v.push_back(pos);  
		}
		for (int i = 0; i < q; i++){
			int a,b,c;  
			cin >> a >> b >> c;  
			--a,--b;  
			grid[a][b] = grid[b][a] = c;  
 		}
 		// floyd-warshall to find all pair min distance
 		for (int k = 0; k < p; k++){
 			for (int i = 0; i < p; i++){
 				for (int j = 0; j < p; j++){
 					grid[i][j] = min(grid[i][j],grid[i][k]+grid[k][j]);  
 				}
 			}
 		}
 		// find the position 
 		int pos,minval = INF; 
 		for (int k = 0; k < p; k++){
 			int val = 0;   
 			bool flag = true;  
 			for (int i = 0; i < v.size(); i++){
 				if (grid[v[i]][k] == INF){
 					// no path 
 					flag = false;  
 					break; 
 				}
 				val += (grid[v[i]][k])*(grid[v[i]][k]);  
 			}
 			if (flag && val < minval){
 				minval = val;  
 				pos = k;  
 			}
 		}
 		cout << pos+1 << " " << minval << endl; 
	}
	return 0; 
}

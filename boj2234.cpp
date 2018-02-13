#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio> 
#include <vector> 
#include <algorithm>
using namespace std; 
// (1)number of rooms in the castle 
// (2)size of the largest room 
// (3)size of the largest room created by removing one wall. 
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);   
const int INF = 987654321;    
int n,m; 
int grid[55][55][4]; 
int visited[55][55];  
// 0: west, 1: north, 2: east, 3: south 
int dy[4] = {0,-1,0,1};  
int dx[4] = {-1,0,1,0}; 
bool inRange(int y,int x){
	return (y >= 0 && y < n && x >= 0 && x < m); 
} 
string toBinary(int x){
	string t = "";  
	while (x){
		if (x%2 == 1) t += "1"; 
		else t += "0"; 
		x /= 2; 
	}
	reverse(t.begin(),t.end()); 
	while (t.size() < 4){
		t = "0"+t;  
	}
	return t;  
}
int area = 0; // keep track of area  
void dfs(int y,int x){ // find how many rooms there are 
	if (visited[y][x]) return;  
	area++;  
	visited[y][x] = 1;   
	for (int i = 0; i < 4; i++){
		int ny = y+dy[i];  
		int nx = x+dx[i];  
		if (inRange(ny,nx) && grid[y][x][i] == 1){
			dfs(ny,nx);  
		}
	} 
}
int main(){	
	IOFAST();  
	cin >> n >> m;  
	swap(n,m);  
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			int x; 
			cin >> x;  
			string s = toBinary(x); 
			for (int k = s.size()-1; k >= 0; k--){
				grid[i][j][s.size()-1-k] = (s[k] == '0' ? 1 : 0);  
			}
		}
	}
	int cnt = 0,maxArea = -INF; 
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){ 
			area = 0;   
			if (!visited[i][j]){
				cnt++;  
				dfs(i,j);  
			}
			maxArea = max(maxArea,area); // constantly update area value 
		}
	}
	cout << cnt << endl; 
	cout << maxArea << endl; 
	// now let us compute the max area when we get rid of one wall 
	int max_after_repair = -INF;  
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			for (int k = 0; k < 4; k++){
				if (grid[i][j][k] == 0){
					grid[i][j][k] = 1; // make it passable.    
					area = 0; 
					memset(visited,0,sizeof(visited));  
					dfs(i,j); // variable area is modified here again 
					max_after_repair = max(max_after_repair,area); 
					grid[i][j][k] = 0;  // backtrack 
				}
			}
		}
	}
	cout << max_after_repair << endl; 
	return 0;  
}

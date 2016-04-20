#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <vector> 
using namespace std; 

vector<char> v; 
int R,C;  
char grid[21][21]; 
int dy[4] = {1,0,-1,0}; 
int dx[4] = {0,1,0,-1};  

bool inRange(int y, int x){
	return (y >= 0 && y < R && x >= 0 && x < C); 
}

int recur(int y, int x){
	v.push_back(grid[y][x]); 
	int res = 1;  
	for (int i = 0; i < 4; i++){
		int ny=y+dy[i],nx=x+dx[i];  
		int temp = 0;  
		if (inRange(ny,nx) && find(v.begin(),v.end(),grid[ny][nx]) == v.end()){
			temp = 1+recur(ny,nx);  
			v.pop_back();  
		}  
		res = max(res,temp); 
	}
	return res;  
}

int main(){ 
	cin >> R >> C; 
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++){
			cin >> grid[i][j];  
		}
	}
	int ans = recur(0,0);  
	cout << ans << endl; 
	return 0; 
}

#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm>
using namespace std;  
char grid[12][6];
int visited[12][6]; 
int dx[4] = {1,0,-1,0}; 
int dy[4] = {0,1,0,-1}; 
bool inRange(int x,int y){
	return (x >= 0 && x < 12 && y >= 0 && y < 6); 
}
/* check if the neighboring puyos amount to geq 4 */
int cnt(int x,int y,char c){
	visited[x][y] = 1;  
	int ret = 0; 
	for (int i = 0; i < 4; i++){
		int nx = x+dx[i]; 
		int ny = y+dy[i]; 
		if (inRange(nx,ny) && grid[nx][ny] == c && !visited[nx][ny]){
			ret += 1+cnt(nx,ny,c); 
		}
	}
	return ret;  
}
/* get rid of neighboring puyos */ 
void dfs(int x,int y,char c){
	grid[x][y] = '.';  
	for (int i = 0; i < 4; i++){
		int nx = x+dx[i]; 
		int ny = y+dy[i]; 
		if (inRange(nx,ny) && grid[nx][ny] == c){
			dfs(nx,ny,c); 
		}
	}
} 
/* for debugging */ 
void printState(){
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 6; j++){
			cout << grid[i][j] << " "; 
		}
		cout << endl; 
	}
}
/* check if grid is empty */ 
bool done(){
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 6; j++){
			if (grid[i][j] != '.') return false; 
		}
	}
	return true; 
}
/* adjusting the grid by pulling down puyos */ 
void adjust(){
	for (int i = 10; i >= 0; i--){
		for (int j = 0; j < 6; j++){
			if (grid[i][j] != '.'){
				int x = i;  
				while (x+1 < 12 && grid[x+1][j] == '.'){
					x++; 
				}
				if (x > i){
					grid[x][j] = grid[i][j];  
					grid[i][j] = '.';  
				}
			}
		}
	}		
}
int main(){
	for (int i = 0; i < 12; i++){
		for (int j = 0; j < 6; j++){
			cin >> grid[i][j]; 
		}
	} 
	int streak = 0; 
	while (1){
		bool change = false;  
		for (int i = 0; i < 12; i++){
			for (int j = 0; j < 6; j++){
				if (grid[i][j] != '.'){
					memset(visited,0,sizeof(visited));  
					if (cnt(i,j,grid[i][j]) >= 3){
						dfs(i,j,grid[i][j]); 
						change = true;  
					}
				}
			}
		}
		adjust(); 
		if (change) streak++;  
		if (!change || done()) break; 
	} 
	cout << streak << endl; 
	return 0; 
}

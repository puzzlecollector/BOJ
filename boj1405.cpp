// Problem Link: https://www.acmicpc.net/problem/1405
#include <iostream>
#include <vector>
#include <cstdio> 
using namespace std; 

bool grid[100][100] = {false}; 
int vx[4] = {1,-1,0,0}; 
int vy[4] = {0,0,1,-1}; 
double prob[4];  

double dfs(int x, int y, int n){
	if (grid[x][y]) return 0; // visits the place that the robot already visited. 
	if (n == 0) return 1; // always succeeds. 
	grid[x][y] = true; 
	double ret = 0.0;  
	for (int i = 0; i < 4; i++){
		ret += dfs(x+vx[i],y+vy[i],n-1)*prob[i]; 
	} 
	grid[x][y] = false; 
	return ret; 
}	

double getProbability(int n, int east, int west, int south, int north){
	prob[0] = east/100.0; 
	prob[1] = west/100.0; 
	prob[2] = south/100.0; 
	prob[3] = north/100.0; 
	return dfs(50,50,n); // assume the robot starts from the middle of the grid. 
}

int main(){
	int n,E,W,S,N;  
	cin >> n >> E >> W >> S >> N; 
	printf("%.10lf\n",getProbability(n,E,W,S,N)); 
	return 0; 
}

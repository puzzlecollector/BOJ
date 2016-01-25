// Problem Link: https://www.acmicpc.net/problem/1780 
// Divide and Conquer Problem. 
#include <iostream> 
#include <cstdlib> 
#include <cstring> 
#include <algorithm> 
using namespace std; 

#define MAX	3000 

int N; 
int cntNegOne,cntZero,cntOne;  
int grid[MAX][MAX];  

int chk(int startR,int endR,int startC,int endC){
	int comp = grid[startR][startC]; 
	for (int i = startR; i < endR; i++){
		for (int j = startC; j < endC; j++){
			if (grid[i][j] != comp){
				return 2; 
			}
		}
	}
	if (comp == -1) return -1; 
	if (comp == 0) return 0; 
	if (comp == 1) return 1;  
	// else 
	return 2; 
} 

void recur(int startR, int endR, int startC, int endC){
	// base cases: 
	if (chk(startR,endR,startC,endC) == -1){
		++cntNegOne;  
		return; 
	}
	if (chk(startR,endR,startC,endC) == 0){
		++cntZero;  
		return; 
	}
	if (chk(startR,endR,startC,endC) == 1){
		++cntOne; 
		return; 
	}
	if (chk(startR,endR,startC,endC) == 2){
		int diffR = (endR-startR)/3; 
		int diffC = (endC-startC)/3; 
		// 3 parts in first column
		recur(startR,startR+diffR,startC,startC+diffC); 
		recur(startR+diffR,startR+2*diffR,startC,startC+diffC); 
		recur(startR+2*diffR,startR+3*diffR,startC,startC+diffC); 
		// 3 parts in second column 
		recur(startR,startR+diffR,startC+diffC,startC+2*diffC);  
		recur(startR+diffR,startR+2*diffR,startC+diffC,startC+2*diffC);  
		recur(startR+2*diffR,startR+3*diffR,startC+diffC,startC+2*diffC);  
		// 3 parts in third column 
		recur(startR,startR+diffR,startC+2*diffC,startC+3*diffC); 
		recur(startR+diffR,startR+2*diffR,startC+2*diffC,startC+3*diffC);  
		recur(startR+2*diffR,startR+3*diffR,startC+2*diffC,startC+3*diffC);  
		return; 
	}
}

int main(){
	cin >> N; 
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> grid[i][j]; 
		}
	}
	recur(0,N,0,N); 
	cout << cntNegOne << endl; 
	cout << cntZero << endl; 
	cout << cntOne << endl; 
	return 0;  
}

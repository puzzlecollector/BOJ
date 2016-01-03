/*
Problem Link: https://www.acmicpc.net/problem/10992 
Another star printing problem. 
*/

#include <iostream> 
#include <cstdio> 
using namespace std; 

int main(){
	int n; 
	cin >> n;  
	char star[n][2*n-1]; 
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 2*n-1; j++){
			star[i][j] = '/'; 
		}
	}
	star[0][(2*n-1)/2] = '*'; 
	int leftDown = (2*n-1)/2, rightDown = (2*n-1)/2; 
	for (int i = 1; i < n-1; i++){
		star[i][--leftDown] = '*'; 
	}
	for (int i = 1; i < n-1; i++){
		star[i][++rightDown] = '*'; 
	}
	for (int i = 0; i < 2*n-1; i++){
		star[n-1][i] = '*'; 
	}
	// printing 
	for (int i = 0; i < n; i++){
		int cnt = 0;  
		for (int j = 0; j < 2*n-1; j++){
			if (i == 0 && cnt == 1){
				break; 
			}
			if (cnt == 2 && i != n-1){
				break; 
			}
			if (star[i][j] == '*'){
				++cnt; 
				cout << '*';  
			}else{
				cout << ' ';  
			}
		}
		cout << endl; 
	}
	return 0; 	
} 

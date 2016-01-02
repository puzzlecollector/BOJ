/*
Problem Link: https://www.acmicpc.net/problem/10990
This is an implementation problem. We have to print the shape of the star as specified 
by the sample outputs. 

An alternative methdo to this would be to place stars at the start and end 
of each row. This solution goes down diagonally left and then right to fill the star instead. 
*/

#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
using namespace std;  

int main(){
	int n; 
	scanf("%d",&n);  
	char star[n][2*n-1]; 
	// initializing star[][] to 
	// contain characters other than '*'. 
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 2*n-1; j++){
			star[i][j] = 'n'; 
		}
	} 
	star[0][(2*n-1)/2] = '*'; 
	int leftPos = (2*n-1)/2, rightPos = (2*n-1)/2;
	// left   
	for (int i = 1; i < n; i++){
		star[i][--leftPos] = '*'; 
	}
	// right 
	for (int i = 1; i < n; i++){
		star[i][++rightPos] = '*';  
	}
	// printing
	for (int i = 0; i < n; i++){
		int chk = 0; 
		for (int j = 0; j < 2*n-1; j++){
			if (chk == 2) break;
			if (i == 0 && chk == 1) break;  
			if (star[i][j] == '*'){
				cout << '*';  
				++chk; 
			} 
			else cout << ' '; 
		}
		cout << endl; 
	}
	return 0; 
}


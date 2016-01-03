/*
Problem Link: https://www.acmicpc.net/problem/10996 
Deducing the pattern then printing stars.  
*/
#include <iostream>
#include <cstdio> 
#include <cstdlib> 
using namespace std; 

int main(){
	int n; 
	cin >> n; 
	// our job is to first generate the pattern
	// and then print this pattern n times.  
	for (int i = 0; i < n; i++){
		if (n%2 == 0){
			// top 
			for (int i = 0; i < n/2-1; i++){
				cout << '*' << ' ';  
			}
			cout << '*' << endl; 
			// bottom 
			for (int i = 0; i < n/2; i++){
				cout << ' ' << '*'; 
			}
			cout << endl; 
		}else if (n%2 == 1){
			// top
			for (int i = 0; i < n/2; i++){
				cout << '*' << ' '; 
			}
			cout << '*' << endl; 
			// bottom
			for (int i = 0; i < n/2; i++){
				cout << ' ' << '*';  
			}
			cout << endl; 
		}
	}
	return 0; 
}



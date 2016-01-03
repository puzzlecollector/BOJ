/*
Problem Link: https://www.acmicpc.net/problem/10991
Another star printing problem. 
*/

#include <iostream> 
#include <cstdio> 
using namespace std; 

int main(){		
	int n;  
	cin >> n; 
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < n-i; j++){
			cout << ' '; 
		}
		for (int j = 0; j < i-1; j++){
			cout << "* ";  
		}
		cout << '*' << endl; 
	}
	return 0; 
}

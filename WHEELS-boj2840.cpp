// Problem Link: https://www.acmicpc.net/problem/2840
#include <iostream>
#include <cstdlib> 
#include <cstdio> 
using namespace std; 

char a[26]; 

int main(){
	int n,k; 
	cin >> n >> k; 
	for (int i = 0; i < n; i++){
		a[i] = '?';  
	}
	int x = 0;  
	for (int i = 0; i < k; i++){
		int s; 
		char c; 
		cin >> s >> c; 
		for (int j = 0; j < s; j++){
			x++; 
			x %= n; 
		}
		if (a[x] != '?' && a[x] != c){
			cout << '!' << endl; 
			return 0;  
		}
		a[x] = c; 
	}
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){
			if (a[i] == a[j] && a[i] != '?'){
				cout << '!' << endl;
				return 0; 
			}
		}
	}
	for (int i = 0; i < n; i++){
		cout << a[x]; 
		x--; 
		if (x == -1) x = n-1; 
	}
	cout << endl; 
	return 0; 
}

// Problem Link: https://www.acmicpc.net/problem/10798
#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
#include <string> 
using namespace std;  

char stuff[5][15]; 
string s;  

int main(){
	for (int i = 0; i < 15; i++){
		for (int j = 0; j < 5; j++){
			stuff[i][j] = '\0';  
		}
	}
	for (int i = 0; i < 5; i++){
		cin >> s;  
		for (int j = 0; j < s.size(); j++){
			stuff[i][j] = s[j]; 
		}
 	}
 	for (int i = 0; i < 15; i++){
 		for (int j = 0; j < 5; j++){
 			if (stuff[j][i] == '\0') continue;  
 			cout << stuff[j][i]; 
 		}
 	}
 	cout << endl; 
 	return 0; 
}

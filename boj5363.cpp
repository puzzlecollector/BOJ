// Problem Link: https://www.acmicpc.net/problem/5363 
// Using istringstream 
#include <iostream> 
#include <string> 
#include <cstdio> 
#include <sstream> 
#include <cctype> 
#include <cstdlib> 
using namespace std; 

int main(){
	int n; 
	cin >> n; 
	cin.ignore(); 
	for (int i = 0; i < n+1; i++){
		string s;
		string front = "", back = ""; 
		int cnt = 0;  
		getline(cin,s); 
		istringstream iss (s); 
		string word; 
		while (iss >> word){
			if (cnt++ >= 2){
				front += word;
				front += " ";  
			}else{
				back += word;  
				back += " ";
			}
		}
		cout << front << back << endl; 
	}
	return 0; 
}

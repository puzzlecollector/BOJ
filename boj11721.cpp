// Problem Link: https://www.acmicpc.net/problem/11721
#include <iostream>
#include <string> 
using namespace std; 

int main(){
	string s; 
	cin >> s; 
	int n = s.size();
	if (n%10 == 0){
		int iter = n/10; 
		for (int i = 0; i < iter; i++){
			for (int j = i*10, cnt = 0; cnt < 10; j++,cnt++){
				cout << s[j]; 
			}
			cout << endl; 
		}
	}else{
		int iter = n/10;  
		int rem = n%10;   
		for (int i = 0; i < iter; i++){
			for (int j = i*10, cnt = 0; cnt < 10; j++,cnt++){
				cout << s[j]; 
			}
			cout << endl; 
		}
		// now print remaining
		for (int i = 10*iter; i < 10*iter+rem; i++){
			cout << s[i]; 
		}
		cout << endl; 
	}
	return 0; 
}

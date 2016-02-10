// Problem Link: https://www.acmicpc.net/problem/11809
// Yoda 
#include <iostream>
#include <cstdio> 
#include <string>
#include <algorithm>
#include <cstdlib>
using namespace std; 

int main(){
	string n,m; 
	cin >> n >> m; 	
	// make the lengths of m and n equal. 	
	if (n.size() < m.size()){
		while (n.size() < m.size()){
			n = '0'+n; 
		}
	}else if (n.size() > m.size()){
		while (n.size() > m.size()){
			m = '0'+m; 
		}
	}
	// compare digits 
	string new_n = "", new_m = "";  
	for (int i = 0; i < (int)n.size(); i++){
		if (n[i] > m[i]){
			new_n += n[i]; 
		}else if (n[i] == m[i]){
			new_n += n[i]; 
			new_m += m[i];  
		}else{
			new_m += m[i]; 
		}
	}
	// get rid of leading zeros
	int i = 0,j = 0; 
	if (new_n[0] == '0'){
		while (new_n[i] == '0' && i < (int)new_n.size()-1){
			++i; 
		}
	}
	if (new_m[0] == '0'){
		while (new_m[j] == '0' && j < (int)new_m.size()-1){
			++j; 
		}
	}
	new_n = new_n.substr(i);  
	new_m = new_m.substr(j); 
	// print answer. 
	cout << (new_n == "" ? "YODA":new_n) << endl; 		
	cout << (new_m == "" ? "YODA":new_m) << endl;
	return 0; 
}

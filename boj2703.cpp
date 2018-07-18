#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <map> 
using namespace std; 
int main(){
	map<char,int> mp; 
	int i = 0;  
	for (char c = 'A'; c <= 'Z'; c++){
		mp[c] = i++; 
	}
	int t; 
	cin >> t; 
	cin.ignore(); 
	while (t--){
		string s,t,code; 
		getline(cin,s); 
		cin >> code;  
		cin.ignore(); 
		for (int i = 0; i < s.size(); i++){
			if (s[i] == ' ') t += " "; 
			else{
				t += code[mp[s[i]]];  
			}
		} 
		cout << t << endl; 
	}
	return 0; 
}

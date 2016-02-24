#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string> 
#include <cstdio> 
using namespace std; 

int main(){
	string s,t=""; 
	getline(cin,s);  
	for (int i = 0; i < s.size(); i++){
		if (s[i] >= 'a' && s[i] <= 'm') s[i] += 13;  
		else if (s[i] >= 'n' && s[i] <= 'z') s[i] -= 13; 
		else if (s[i] >= 'A' && s[i] <= 'M') s[i] += 13; 
		else if (s[i] >= 'N' && s[i] <= 'Z') s[i] -= 13; 
		t += s[i]; 
	}
	cout << t << endl; 
	return 0; 
}

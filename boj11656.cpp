#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std; 

int main(){
	string s; 
	cin >> s;  
	vector<string> v; 
	for (int i = 0; i < (int)s.size(); i++){
		v.push_back(s.substr(i));  
	}
	sort(v.begin(),v.end()); 
	for (int i = 0; i < (int)v.size(); i++){
		cout << v[i] << endl;
	}
	return 0; 
}

#include <iostream> 
#include <cstdlib> 
#include <string> 
#include <algorithm> 
#include <map> 
#include <vector> 
using namespace std; 

int main(){
	map<char,int> mp; 
	for (int i = 0; i < 26; i++){
		mp[char(i+97)] = 0; 
	}
	int n; 
	string name; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> name; 
		mp[name[0]]++;  
	}
	vector<char> v;  
	for (int i = 0; i < 26; i++){
		if (mp[char(i+97)] >= 5){
			v.push_back(char(i+97));  
		}
	}
	if (v.empty()){
		cout << "PREDAJA" << endl; 
	}else{
		for (int i = 0; i < v.size(); i++){
			cout << v[i]; 
		}
		cout << endl; 
	}
	return 0; 
}

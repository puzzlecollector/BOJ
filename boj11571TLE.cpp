#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <cassert>
#include <vector>
#include <utility>
#include <algorithm> 
using namespace std; 

int cycleLen(int a, int b){
	int len = 0; 
	map<int,int> mp; 
	while (!mp.count(a)){
		mp.insert(pair<int,int>(a,len));  
		a = (a%b)*10; 
		++len;  
	}
	return len-mp[a];  
}

string toString(int n){
	stringstream ss; 
	ss << n; 
	return ss.str(); 
}

int main(){
	int t; 
	cin >> t; 
	while (t--){
		int a,b; // we will find a/b
		cin >> a >> b; assert(b != 0); 
		int len = cycleLen(a,b),cnt = 0, dot = 0; 
		map<int,int> mp;
		string comp = ""; 
		string s = ""; 
		while (true){
			if (cnt == len) break; 
			if (mp.count(a) && cnt < len){
				s += toString(a/b); 
				++cnt; 
				a = (a%b)*10; 
				continue;   	
			}
			mp.insert(pair<int,int>(a,len));  
			comp += toString(a/b);   
			if (dot++ == 0) comp += ".";  
			a = (a%b)*10;  
		}	
		int idx; 
		if (s == "0" && comp[0] == '0'){
			idx = comp.size()-1;  
		}else{
			idx = comp.find(s);  
		}
		for (int i = 0; i < comp.size(); i++){
			if (i == idx){
				cout << "("; 
			}
			cout << comp[i]; 
		}
		cout << ")" << endl; 
	}
	return 0; 
}

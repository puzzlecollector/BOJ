// simple string search problem 
#include <iostream>
#include <cstdlib> 
#include <algorithm>
using namespace std; 
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);  
	string hay,needle; 
	getline(cin,hay); 
	getline(cin,needle);  
	int len = 0,cnt = 0;  
	if (needle.size() > hay.size()){
		cout << 0 << endl; 
		return 0; 
	}
	for (int i = 0; i < hay.size(); i += len){
		bool flag = false; 
		if (hay.size()-i < needle.size()) continue;   
		for (int j = 0; j < needle.size(); j++){
			if (hay[i+j] != needle[j]){
				flag = true;  
				break; 
			}
		}
		if (flag){
			len = 1;  
		}else{
			cnt++;  
			len = needle.size();  
		}
	}
	cout << cnt << endl; 
	return 0;  
}

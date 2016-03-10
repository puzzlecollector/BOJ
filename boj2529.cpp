// all the selected numbers have to be different.  
#include <iostream>
#include <string>
#include <cstdio>
#include <cstring> 
#include <algorithm> 
#include <vector> 
using namespace std; 

char a[15];  
int n; 
vector<string> v;  

void recur(int left, int i, string str){
	if (i == n){
		str += char(left+48); 
		v.push_back(str);  
		return; 
	}
	if (a[i] == '<'){
		for (int j = left+1; j <= 9; j++){
			if (str.find(char(j+48)) != string::npos) continue; 
			recur(j,i+1,str+char(left+48)); 
		}
	}else if (a[i] == '>'){
		for (int j = left-1; j >= 0; j--){
			if (str.find(char(j+48)) != string::npos) continue;  
			recur(j,i+1,str+char(left+48)); 
		}
	}
}

int main(){
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i];  
	}
	for (int i = 0; i <= 9; i++){
		recur(i,0,""); 
	}
	sort(v.begin(),v.end()); 
	cout << v[v.size()-1] << endl;
	cout << v[0] << endl; 
	return 0; 	
}

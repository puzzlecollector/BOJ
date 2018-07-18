#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std; 
int main(){
	vector<string> v(3); 
	cin >> v[0] >> v[1] >> v[2];  
	for (int j = 0; j < 3; j++){
		int cnt = 1,maxval = -1;  
		string s = v[j]; 
		for (int i = 0; i+1 < s.size(); i++){
			if (s[i] == s[i+1]){
				cnt++;  
			}else if (s[i] != s[i+1]){
				maxval = max(maxval,cnt); 
				cnt = 1;  
			}
		}
		maxval = max(maxval,cnt); 
		cout << maxval << endl; 
	}
	return 0; 
}

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath> 
using namespace std; 

int process(int n){
	int cnt = 0; 
	vector<int> v;  
	while (n != 6174){
		++cnt; 
		while (n){
			v.push_back(n%10); 
			n /= 10;  
		}
		if (v.size() < 4){
			while (v.size() < 4){
				v.push_back(0); 
			}
		}
		sort(v.begin(),v.end()); 
		int maxi = 1000*v[3] + 100*v[2] + 10*v[1] + v[0]; 
		int mini = 1000*v[0] + 100*v[1] + 10*v[2] + v[3]; 
		n = maxi-mini;  
		v.clear();  
	}
	return cnt; 
}


int main(){
	int t; 
	cin >> t; 
	for (int i = 0; i < t; i++){
		int n; 
		cin >> n;  
		int ans = process(n);  
		cout << ans << endl; 
	}
	return 0; 
}

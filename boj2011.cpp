// Problem Link: https://www.acmicpc.net/problem/2011 
// failed to get an accept. Will work on it...
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string> 
using namespace std;  

#define MOD 1000000
typedef long long ll; 

ll dp[50001];  

int main(){
	string s;  
	cin >> s;  
	int n = (int)s.size();  
	dp[0] = 1; 
	dp[1] = 1; 
	for (int i = 2; i <= n; i++){
		int val = (s[i-2]-'0')*10 + (s[i-1]-'0');  
		if (val >= 10 && val <= 26){
			dp[i] = ((dp[i-1]%MOD)+(dp[i-2]%MOD))%MOD; 
		}else{
			dp[i] = dp[i-1]; 
		}
	}
	cout << dp[n] << endl; 
	return 0;  
}

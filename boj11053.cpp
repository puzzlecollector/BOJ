// Problem Link: https://www.acmicpc.net/problem/11053
#include <iostream>
#include <cstdlib> 
#include <algorithm> 
using namespace std; 

#define MAX 1001

int a[MAX]; 
int dp[MAX+1];  

int main(){
	int n,res=0; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	for (int i = 0; i < n; i++){
		dp[i] = 1; 
		for (int j = 0; j < i; j++){
			if (a[i] > a[j]){
				dp[i] = max(dp[i],1+dp[j]);  
			}
		}
		res = max(res,dp[i]); 
	}
	cout << res << endl; 
	return 0; 
}

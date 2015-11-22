/*
Problem Link: https://www.acmicpc.net/problem/2293
반복적 동적 계획법 방법. 메모리를 훨씬 덜 차지한다. 맞았습니다 판정을 받음!! 
*/ 
#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm> 
using namespace std; 

int n,k; 
int a[101]; 

int main(){
	cin >> n >> k;  
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	int dp[k+1]; 
	memset(dp,0,sizeof(dp)); 
	dp[0] = 1; 
	for (int i = 0; i < n; i++){
		for (int j = a[i]; j <= k; j++){
			dp[j] += dp[j - a[i]]; 
		}
	}
	int ans = dp[k]; 
	cout << ans << endl;
	return 0; 
}

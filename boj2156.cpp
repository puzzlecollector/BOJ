// Problem Link: https://www.acmicpc.net/problem/2156
#include <iostream>
#include <cstdio> 
#include <algorithm> 
#include <cstdlib> 
using namespace std; 

int dp[10001];  
int a[10001];  

int main(){
	int n; 
	scanf("%d",&n); 
	for (int i = 1; i <= n; i++){
		scanf("%d",&a[i]); 
	}
	dp[1] = a[1]; 
	dp[2] = dp[1] + (n >= 2?a[2]:0);  
	int maxi = max(dp[1],dp[2]);  
	for (int i = 3; i <= n; i++){
		dp[i] = max(dp[i-2],dp[i-3]+a[i-1])+a[i];  
		dp[i] = max(dp[i-1],dp[i]);  
		maxi = max(dp[i],maxi);  
	}
	printf("%d\n",maxi);  
	return 0; 
}

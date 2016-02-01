// Problem Link: https://www.acmicpc.net/problem/2294#
#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
#include <climits> 
using namespace std; 

int n,k; 
int coins[101]; 
int dp[10001]; 

int minCoins(int m, int V){
	dp[0] = 0;  // if the value we have to make is equal to 0. 
	for (int i = 1; i <= V; i++){
		dp[i] = INT_MAX; // initializing dp table.  
	}
	for (int i = 1; i <= V; i++){
		for (int j = 0; j < m; j++){
			if (coins[j] <= i){
				int res = dp[i-coins[j]];  
				if (res != INT_MAX && res + 1 < dp[i]){
					dp[i] = res + 1; 
				}
			}
		}
	}
	return dp[V]; 
}

int main(){
	cin >> n >> k; 
	for (int i = 0; i < n; i++){
		cin >> coins[i];  
	}
	int ans = minCoins(n,k); 
	cout << ans << endl; 
	return 0; 
}

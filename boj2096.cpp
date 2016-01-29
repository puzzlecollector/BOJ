// https://www.acmicpc.net/problem/2096
// simple bottom-up Dynamic Programming 
#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <algorithm> 
using namespace std; 

#define MAXN 100001

int n; 
int dp[MAXN][3], dp2[MAXN][3]; // dp stores max values, dp2 stores min values.
int main(){
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> dp[i][0] >> dp[i][1] >> dp[i][2];
		dp2[i][0] = dp[i][0], dp2[i][1] = dp[i][1], dp2[i][2] = dp[i][2];  
	}
	// let's find max first. 
	for (int i = n-2; i >= 0; i--){
		dp[i][0] += max(dp[i+1][0],dp[i+1][1]); 
		dp[i][1] += max(dp[i+1][0],max(dp[i+1][1],dp[i+1][2]));  
		dp[i][2] += max(dp[i+1][1],dp[i+1][2]); 
	}
	int maxi = max(dp[0][0],max(dp[0][1],dp[0][2])); 
	// now let's find min 
	for (int i = n-2; i >= 0; i--){
		dp2[i][0] += min(dp2[i+1][0],dp2[i+1][1]); 
		dp2[i][1] += min(dp2[i+1][0],min(dp2[i+1][1],dp2[i+1][2]));  
		dp2[i][2] += min(dp2[i+1][1],dp2[i+1][2]); 
	}
	int mini = min(dp2[0][0],min(dp2[0][1],dp2[0][2])); 
	cout << maxi << " " << mini << endl; 
	return 0; 
}

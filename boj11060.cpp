#include <iostream>
#include <cstdio>
#include <cstring> 
#include <cstdlib>
#include <algorithm> 
using namespace std; 

#define INF 987654321 

int a[1001];  
int dp[1001];  // dp[i] = minimum number of jumps to reach position i. 

int main(){
	int n; 
	cin >> n;   
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	if (n == 1){
		// if n = 1, then we are already at the end of the maze, so no jumps required at all. 
		cout << 0 << endl; 
		return 0; 
	}
	(a[0] == 0 ? dp[0] = INF : dp[0] = 0); 
	for (int i = 1; i < n; i++){
		dp[i] = INF; 
		for (int j = 0; j < i; j++){
			for (int k = 1; k <= a[j]; k++){
				if (j+k == i && dp[j] != INF){
					// i.e. if we can reach position i from position j, given that position j is reachable, then 
					// update dp[i]. 
					dp[i] = min(dp[i],dp[j]+1);  // the value of dp[j] is the same anyways for all k steps, so no need to compare anyore. 
					break; 
				}
			}
		}
	}
	if (dp[n-1] == INF) cout << -1 << endl;
	else cout << dp[n-1] << endl; 
	return 0;  
}

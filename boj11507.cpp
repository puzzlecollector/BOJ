#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <algorithm> 
using namespace std; 

#define MOD 10007

int dp[1001][10]; // dp[i][j]: number of numbers with length i and leftmost number j. 

int main(){
	int n; 
	scanf("%d",&n);
	for (int i = 0; i <= 9; i++){
		dp[0][i] = 0;  
		dp[1][i] = 1; 
	} 
	for (int i = 2; i <= n; i++){
		for (int j = 0; j <= 9; j++){
			for (int k = j; k <= 9; k++){
				dp[i][j] += dp[i-1][k];  
				dp[i][j] %= MOD;  
			}
		}
	}
	// return answer. 
	int ans = 0; 
	for (int i = 0; i <= 9; i++){
		ans += dp[n][i];  
		ans %= MOD;  
	}
	printf("%d\n",ans);  
	return 0; 
}

#include <iostream>
#include <algorithm> 
#include <cstdlib> 
#include <cstring> 
using namespace std;  

#define MAXN 17
#define INF 987654321

int w[MAXN][MAXN];  
int dp[(1<<17)+5][17];  

int main(){
	int n,ans,p; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> w[i][j];  
		}
	}
	// floyd-warshall algorithm 
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				w[i][j] = min(w[i][j],w[i][k]+w[k][j]);  
			}
		}
	}
	memset(dp,-1,sizeof(dp));  
	dp[1][0] = 0; 
	// TSP 
	for (int i = 1; i < (1<<n); i++){// current state
		for (int j = 0; j < n; j++){ // during the current state, the last visit is j. 
			if (dp[i][j] == -1) continue; 
			for (int k = 1; k < n; k++){
				// the next state is k 
				if ((i & (1<<k)) != 0) continue; 
				p = (i | (1<<k));  
				if (dp[p][k] == -1) dp[p][k] = dp[i][j] + w[j][k];    
				dp[p][k] = min(dp[p][k],dp[i][j]+w[j][k]);  
			}
		}
	}
	ans = INF;  
	for (int i = 1; i < n; i++){
		if (dp[(1<<n)-1][i] > 0) ans = min(ans,dp[(1<<n)-1][i]+w[i][0]);  
	}
	cout << ans << endl;
	return 0; 
}

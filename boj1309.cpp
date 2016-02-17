#include <iostream>
#include <cstdio> 
#include <cstdlib>
#include <algorithm> 
using namespace std;

#define MOD 9901
 
long long dp[100001];
int n;  

int main(){
	scanf("%d",&n); 
	dp[0] = 1; 
	dp[1] = 3; 
	for (int i = 2; i <= n; i++){
		dp[i] = ((2*dp[i-1])%MOD+(dp[i-2])%MOD)%MOD;  
	}
	printf("%lld\n",dp[n]);
	return 0; 
}

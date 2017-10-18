#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector> 
#include <algorithm> 
using namespace std;  
typedef long long ll;  
bool flag = false;  
ll mod = 100000;  
ll dp[203][203]; 
int n; 
char str[203]; 
char leftpos[] = "({["; 
char rightpos[] = ")}]";  
ll solve(int l,int r){
	if (l > r) return 1; 
	ll &ret = dp[l][r]; 
	if (ret != -1) return ret;  
	ret = 0;  
	for (int i = l+1; i <= r; i += 2){
		for (int j = 0; j < 3; j++){
			if (str[l] == leftpos[j] || str[l] == '?'){
				if (str[i] == rightpos[j] || str[i] == '?'){
					ll v = (solve(l+1,i-1)*solve(i+1,r)); 
					if (v >= mod) v = mod+v%mod; 
					ret += v;  
				}
			}
		}
	}
	return ret; 
}
int main(){
	scanf("%d %s",&n,str);  
	if (n%2 == 1){
		printf("0\n"); 
		return 0; 
	}
	memset(dp,-1,sizeof(dp)); 
	if (solve(0,n-1) < mod){
		printf("%lld\n",solve(0,n-1)); 
	}else{
		printf("%05lld\n",solve(0,n-1)%mod);  
	}
	return 0;  
}

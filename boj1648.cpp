#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
#include <cstring> 
#include <vector> 
using namespace std;  

const int mod = 9901; 
int dp[2][1<<15];  
int n,m;  
void solve(){
	int *crt = dp[0], *next = dp[1];  
	crt[0] = 1;  
	for (int i = n-1; i >= 0; i--){
		for (int j = m-1; j >= 0; j--){
			for (int used = 0; used < (1<<m); used++){
				if ((used >> j & 1)){
					next[used] = crt[used & ~(1<<j)]; 
				}else{
					int res = 0;  
					if (j+1 < m && !(used >> (j+1)&1)){
						res += crt[used|(1<<(j+1))];  
					}
					if (i+1 < n){
						res += crt[used|1<<j];  
					}
					next[used] = res%mod;  
				}
			}
			swap(crt,next);  
		}
	}
	cout << crt[0] << endl; 
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);  
	cin >> n >> m; 
	solve();  
	return 0; 
}

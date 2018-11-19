#include <iostream>
#include <cstdlib>
using namespace std; 
typedef long long ll;  
const ll mod = (ll)1e9+7;  
int main(){
	ll A[64] = {1,}, X, res = 1LL;  
	cin >> A[1] >> X;  
	A[1] %= mod;  
	for (int i = 2; i < 64; i++){
		A[i] = (1LL*A[i-1]*A[i-1])%mod;  
	}
	for (int i = 0; i < 63; i++){
		if (X & 1LL<<i){
			res = (1LL*res*A[i+1])%mod; 
		}
	}
	cout << res << endl; 
	return 0; 
}

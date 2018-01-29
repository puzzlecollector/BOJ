#include <iostream> 
#include <cstdlib>
#include <cstring> 
#include <algorithm> 
#include <vector> 
using namespace std;  
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
int a[20][20]; // a[i][j]: cost for turning on generator j with generator i.  
string s;  
int dp[1<<17];  
int N,P;  // N: no. of generators, P: at least P generators must be on 
const int INF = 987654321; 
int solve(int bit,int cnt){	
	if (cnt >= P) return 0; 
	int &ret = dp[bit];  
	if (ret != -1) return ret; 
	ret = INF; 
	for (int i = 0; i < N; i++){
		if (bit & (1<<i)){ // if generator i is on 
			for (int j = 0; j < N; j++){
				if (bit & (1<<j)) continue; // if j is already on too, no need to turn it on so skip 
				ret = min(ret,a[i][j]+solve(bit|(1<<j),cnt+1));  
			}
		}
	}
	return ret; 
}	
int main(){
	IOFAST(); 
	cin >> N; 
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> a[i][j];  
		}
	}
	cin >> s; 
	cin >> P;  
	if (P == 0){ // edge case  
		cout << 0 << endl; 
		return 0;  
	}
	memset(dp,-1,sizeof(dp));  
	int bit = 0, cnt = 0; // bit: info on which generators are on 
	// cnt: how many generators are on now?  
	for (int i = 0; i < N; i++){
		if (s[i] == 'Y'){
			++cnt; 
			bit |= (1<<i);  
		}
	}
	int ans = solve(bit,cnt);  
	if (ans == INF) cout << -1 << endl; 
	else cout << ans << endl; 
	return 0; 
}

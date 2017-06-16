#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <climits> 
#include <algorithm>
using namespace std; 
typedef long long ll;  
ll a[5555],ans[3]; 
ll absll(ll x){
	if (x < 0) return -x; 
	return x;  
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); 
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i];  
	}
	sort(a,a+n); 
	ll minval = LLONG_MAX;  
	for (int i = 0; i < n; i++){
		int l = 0, r = n-1;  
		while (l != r){
			if (i != l && i != r){
				if (minval > absll(a[l]+a[i]+a[r])){
					minval = absll(a[l]+a[i]+a[r]);  
					ans[0] = a[l], ans[1] = a[i], ans[2] = a[r];  
				}
			}
			if (absll(a[l+1]+a[i]+a[r]) >= absll(a[l]+a[i]+a[r-1])){
				r--;  
			}else{
				l++;  
			}
		}
	}
	sort(ans,ans+3); 
	for (int i = 0; i < 3; i++){
		cout << ans[i]; 
		if (i == 2) cout << endl; 
		else cout << " "; 
	}
	return 0; 
}

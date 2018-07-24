#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;  
const int maxn = 1299709+5;  
int prime[maxn]; 
vector<int> plist; 
void eratos(){
	typedef long long ll;  
	for (int i = 0; i < maxn; i++){
		prime[i] = 1;  
	}
	prime[0] = prime[1] = 0;  
	for (ll i = 2; i < (ll)maxn; i++){
		if (prime[i]){
			plist.push_back(i);  
			for (ll j = i*i; j < (ll)maxn; j += i){
				prime[j] = 0; 
			}
		}
	}
}
int main(){
	int t,k; 
	cin >> t;  
	eratos(); 
	while (t--){	
		cin >> k; // k is greater than 1 
		vector<int>::iterator it = lower_bound(plist.begin(),plist.end(),k); 
		if (*it == k){
			cout << 0 << endl; 
		}else{
			vector<int>::iterator jt = it-1; 
			cout << *it - *jt << endl; 
		}
	}  
	return 0; 
}

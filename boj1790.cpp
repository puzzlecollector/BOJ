#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int len(int x){
	int l = 0; 
	if (x == 0) return 0; 
	while (x){
		x /= 10; 
		l++; 
	}
	return l; 
}
int main(){
	int n,k,l = 0,i; 
	cin >> n >> k; 
	for (i = 1; i <= n; i++){
		l += len(i); 
		if (l >= k) break; 
	}
	while (l > k){
		i /= 10; 
		l--; 
	}
	if (l == k) cout << i%10 << endl; 
	else cout << -1 << endl; 
	return 0;  
}

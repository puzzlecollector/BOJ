#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
using namespace std;  
int a[300005]; 
int main(){
	int n,k; 
	cin >> n >> k; 
	vector<int> v;  
	for (int i = 0; i < n; i++){
		cin >> a[i]; 
	}
	for (int i = 0; i+1 < n; i++){
		v.push_back(a[i+1]-a[i]);  
	}
	sort(v.begin(),v.end(),greater<int>());  
	int ans = a[n-1]-a[0];  
	for (int i = 0; i < k-1; i++){
		ans -= v[i];  
	}
	cout << ans << endl; 
	return 0;  
}

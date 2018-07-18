#include <iostream>
using namespace std; 
int n;  
int a[101];  
bool chk(){
	for (int i = 0; i+1 < n; i++){
		if (a[i] >= a[i+1]) return false; 
	}
	return true; 
}
int main(){
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i];  
	}
	int ans = 0; 
	while (!chk()){
		for (int i = 0; i+1 < n; i++){
			if (a[i] >= a[i+1]){
				ans += a[i]-(a[i+1]-1); 
				a[i] = a[i+1]-1;  
			}
		}
	}
	cout << ans << endl; 
	return 0; 
}

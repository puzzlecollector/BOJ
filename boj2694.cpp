#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 

int a[10001], n; 

int calc(int mid){
	int sum = 0; 
	for (int i = 0; i < n; i++){
		sum += a[i];  
		if (sum == mid){
			sum = 0; 
		}else if (sum < mid){
			continue; 
		}else{
			return 0;  
		}
	}
	if (sum != 0) return 0; 
	return 1; // i.e. for us to return true, the sum has to equal to mid all the way. 
}

int main(){
	int t; 
	cin >> t; 
	while (t--){
		cin >> n; 
		int sum = 0, ans; 
		for (int i = 0; i < n; i++){
			cin >> a[i]; sum += a[i]; 
		}
		for (int i = 0; i <= sum; i++){
			if (calc(i) == 1){
				ans = i; 
				break; 
			}
		}
		cout << ans << endl; 
	}	
	return 0; 
}

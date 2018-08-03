#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 
int a[101]; 
int main(){
	int n,m; 
	cin >> n >> m; 
	for (int i = 0; i < n; i++){
		cin >> a[i];  
	}
	int mindiff = 2e9,ans = -1;  
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){
			for (int k = j+1; k < n; k++){
				int sum = a[i]+a[j]+a[k]; 
				if (sum <= m && mindiff > m-sum){
					mindiff = m-sum;  
					ans = sum; 
				}
			}
		}
	}
	cout << ans << endl; 
	return 0;  
}

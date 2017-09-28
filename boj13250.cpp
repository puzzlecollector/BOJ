// bottom up code 
#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm>
#include <vector> 
using namespace std;  
const int maxn = 1111111; 
double dp[maxn]; 
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int n; 
	cin >> n; 
	dp[0] = 0; 
	dp[1] = 1;  
	for (int i = 2; i <= n; i++){
		for (int j = 1; j <= 6; j++){
			if (i-j >= 0){
				dp[i] += (dp[i-j]+1)*(1.0/6.0);   
			}else{
				dp[i] += 1.0/6.0;  
			} 
		}
	}
	cout.setf(ios::fixed); 
	cout.setf(ios::showpoint); 
	cout.precision(12); 
	cout << dp[n] << endl; 
	return 0; 
}

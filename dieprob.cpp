#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <cstring> 
using namespace std; 
const int maxn = 1111111; 
double cache[maxn]; 
double solve(int n){
	if (n == 0) return 0.0;  
	if (n == 1) return 1.0;
	double &ret = cache[n];
	if (ret != 0.0) return ret; 
	ret = 0.0; // for clarity 
	for (int dieRollResult = 1; dieRollResult <= 6; dieRollResult++){
		if (n-dieRollResult >= 0){
			ret += (1.0/6.0)*(1+solve(n-dieRollResult)); 
		}else{
			ret += (1.0/6.0);  
		}
	} 
	return ret;  
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL); 
	int n; 
	cin >> n; 
	double ans = solve(n); 
	cout.setf(ios::fixed); 
	cout.setf(ios::showpoint); 
	cout.precision(12); 
	cout << ans << endl; 
	return 0; 
}

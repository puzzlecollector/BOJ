#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[11][2]; 
int n; // total number of recipes 
const int INF = (int)2e9+88;  
int solve(int i,int x,int y){
	if (i == n){
		if (x == -1 && y == -1) return INF; 
		return abs(x-y);  
	}
	if (x == -1 && y == -1){
		return min(solve(i+1,x,y),solve(i+1,a[i][0],a[i][1])); 
	}
	return min(solve(i+1,x,y),solve(i+1,x*a[i][0],y+a[i][1]));  
}
int main(){
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i][0] >> a[i][1]; 
	}
	int ans = solve(0,-1,-1);  
	cout << ans << endl; 
	return 0;  
}

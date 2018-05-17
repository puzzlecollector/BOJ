#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm>
using namespace std; 
int a[10005],b[10005]; 
int cache[10005][2]; 
int n,m; // length of first sequence, length of second sequence 
int solve(int i,int path){
	if (path == 0 && i == n) return 0;  
	if (path == 1 && i == m) return 0; 
	int &ret = cache[i][path]; 
	if (ret != -1) return ret; 
	if (path == 0){
		ret = a[i]+solve(i+1,path); 
		if (i < m && a[i] == b[i]){
			ret = max(ret,a[i]+solve(i+1,!path)); 
		}
	}else if (path == 1){
		ret = b[i]+solve(i+1,path); 
		if (i < n && a[i] == b[i]){
			ret = max(ret,b[i]+solve(i+1,!path)); 
		}
	}
	return ret; 
}
int main(){
	while (true){
		cin >> n;  
		if (n == 0) break; 
		for (int i = 0; i < n; i++){
			cin >> a[i]; 
		}
		cin >> m; 
		for (int i = 0; i < m; i++){
			cin >> b[i]; 
		}
		memset(cache,-1,sizeof(cache)); 
		int ans = max(solve(0,0),solve(0,1)); 
		cout << ans << endl; 
	}
	return 0; 
}

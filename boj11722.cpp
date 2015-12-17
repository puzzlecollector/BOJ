// Problem link: https://github.com/iljimae0418/Random-Codeforces-Topcoder/blob/master/algospotLIS.cpp
#include <iostream> 
#include <cstdlib> 
#include <cstring> 
#include <algorithm> 
using namespace std; 

int n; 
int a[1001];
int cache[1002];   

int lds(int start){
	int& ret = cache[start+1];  
	if (ret != -1) return ret; 
	// there is always a[start], so length is at least 1. 
	ret = 1; 
	for (int next = start+1; next < n; next++){
		if (start == -1 || a[start] > a[next]){
			ret = max(ret,1+lds(next));  
		}
	}
	return ret;  
}

int main(){
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i];  
	}
	// initialize cache 
	memset(cache,-1,sizeof(cache)); 
	// calculate answer. 
	int ans = lds(-1)-1; 
	cout << ans << endl; 
	return 0; 
}

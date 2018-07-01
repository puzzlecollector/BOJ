#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
const int INF = (int)2e9+88;  
int a[1000005]; 
int N,K; 
int main(){
	cin >> N >> K;  
	for (int i = 0; i < N; i++){
		cin >> a[i]; 
	}
	int l = 0,r = 0,seen = 0,minSize = INF; 
	while (l < N){
		while (r < N && seen < K){
			if (a[r] == 1) seen++; 
			r++; 
		}
		if (seen >= K) minSize = min(minSize,r-l);
		if (a[l] == 1) seen--;  
		l++; 
	}
	cout << (minSize == INF ? -1 : minSize) << endl; 
	return 0; 
}


// greedy coin problem. 
#include <iostream> 
#include <cstdio>
#include <algorithm> 
#include <vector> 
using namespace std; 

int main(){
	int n,k; 
	scanf("%d%d",&n,&k);  
	int a[11];  
	for (int i = 0; i < n; i++){
		scanf("%d",&a[i]);  
	}
	int cnt = 0; 
	for (int i = n-1; i >= 0; i--){
		if (k == 0) break; 
		if (k >= a[i]){
			while (k >= a[i]){
				k -= a[i]; 
				++cnt;  
			}
		}
	}
	printf("%d\n",cnt);  
	return 0;  
}

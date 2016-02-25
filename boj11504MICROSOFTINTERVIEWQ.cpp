#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm> 
using namespace std; 

int lis[1001], lds[1001], a[1001]; 

int main(){
	int n; 
	scanf("%d\n",&n);  
	for (int i = 0; i < n; i++){
		scanf("%d",&a[i]);  
	}
	// find lis first, where lis[i] contains the length of longest increasing subsequence that 
	// ends with a[i].  
	for (int i = 0; i < n; i++){
		lis[i] = 1;  
		for (int j = 0; j < i; j++){
			if (a[j] < a[i]){
				lis[i] = max(lis[i],lis[j]+1);  
			}
		}
	}
	// next, find lds, where lds[i] contains the length of longest decreasing subsequence gthat
	// starts with a[i].  
	for (int i = 0; i < n; i++){
		lds[i] = 1; 
	}
	for (int i = n-2; i >= 0; i--){
		for (int j = n-1; j > i; j--){
			if (a[j] < a[i]){
				lds[i] = max(lds[i],lds[j]+1);  
			}
		}
	}
	int ans = 0;  
	for (int i = 0; i < n; i++){
		ans = max(ans,lis[i]+lds[i]-1); 
	}
	printf("%d\n",ans); 
	return 0; 
} 

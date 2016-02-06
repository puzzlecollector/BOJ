// Problem Link: https://www.acmicpc.net/problem/10815
#include <iostream>
#include <cstdio> 
#include <cstdlib> 
#include <algorithm> 
using namespace std; 

int a[500001], b[500001];  

int main(){
	int n,m; 
	scanf("%d",&n);  
	for (int i = 0; i < n; i++){
		scanf("%d",&a[i]); 
	}
	scanf("%d",&m);  
	for (int i = 0; i < m; i++){
		scanf("%d",&b[i]);  
	}
	sort(a,a+n); 
	for (int i = 0; i < m; i++){
		if (binary_search(a,a+n,b[i])) printf("1 ");  
		else printf("0 "); 
	}
	printf("\n"); 
	return 0; 
}

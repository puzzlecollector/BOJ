// problem link: https://www.acmicpc.net/problem/2548
#include <iostream>
#include <cstdlib> 
#include <cstdio> 
#include <algorithm> 
using namespace std; 

int a[20001];  

int main(){
	int n; 
	scanf("%d",&n); 
	for (int i = 0; i < n; i++){
		scanf("%d",&a[i]);   
	}
	sort(a,a+n);  
	if (n%2){
		printf("%d\n",a[n/2]);  
	}else{
		int mid1 = a[n/2-1], mid2 = a[n/2]; 
		int sum1 = 0, sum2 = 0; 
		for (int i = 0; i < n; i++){
			sum1 += abs(a[i]-mid1);  
			sum2 += abs(a[i]-mid2); 
		}
		printf("%d\n",sum1 >= sum2 ? mid1:mid2); 
	}
	return 0; 
}

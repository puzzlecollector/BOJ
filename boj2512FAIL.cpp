// got it wrong, will try to fix it when I have time. 
// solve using binary search. 
// https://www.acmicpc.net/problem/2512
#include <iostream> 
#include <cstdio> 
#include <cstdlib>
#include <algorithm>
using namespace std;  

int a[10001]; 

void binaryFind(int n, int low, int high, int total, int &maxi){
	// n: total number of elements 
	while (high-low > 1){
		int mid = (low+high)/2; 
		int cnt = 0, sum = 0; 
		for (int i = 0; i < n; i++){
			if (a[i] < mid){
				++cnt; 
				sum += a[i];  
			}else{
				sum += (n-cnt)*mid; 
				break; 
			}
		}
		if (sum <= total){
			maxi = max(mid,maxi);  
			low = mid;  
		}else{
			high = mid;  
		}
	}
	return; 
}	

int main(){
	int n;  
	int sum = 0, total; 
	scanf("%d",&n);  
	for (int i = 0; i < n; i++){
		scanf("%d",&a[i]);  
		sum += a[i];  
	}	
	scanf("%d",&total); 
	if (sum <= total){
		printf("%d\n",a[n-1]); 
		return 0; 
	}
	sort(a,a+n); 
	int maxi = 0;  
	binaryFind(n,a[0],a[n-1],total,maxi);  
	printf("%d\n",maxi); 
	return 0; 
}	

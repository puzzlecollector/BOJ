// correct version of 1436. Got it right afterall! :) 

#include <iostream>
#include <cstdio> 
#include <algorithm> 
using namespace std; 

int a[10001];  

bool chk(int i){
	while (i >= 666){
		if (i%1000 == 666){
			return true; 
		}
		i /= 10; 
	}
	return false; 
}

int main(){
	a[1] = 666;  
	int n; 
	scanf("%d",&n);  
	for (int i = 666, k = 1; k <= 10000; i++){
		if (chk(i)){
			a[k] = i; 
			++k;  
		}
	}
	printf("%d\n",a[n]);  
	return 0; 
}

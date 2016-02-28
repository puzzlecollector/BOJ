// Test case의 4%정도 통과하고 TLE. 
#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <cstdio>
using namespace std;  

#define MOD 1000000000 
long long cnt = 0;  

// first let's construct a recursive algorithm:  
void chooseKSum(int N, int K, int sum){
	if (K == 0 && sum == N){
		++cnt;  
		cnt %= MOD;  
		return; 
	}
	for (int i = 1; i <= N; i++){
		if (sum+i <= N){
			chooseKSum(N,K-1,sum+i);  
		}
	}
}

int main(){
	int N,K; 
	scanf("%d %d",&N,&K);  
	chooseKSum(N,K,0);  
	printf("%lld\n",cnt+K); // we add at the end because we didn't account for the 0 case.  
	return 0;  
}

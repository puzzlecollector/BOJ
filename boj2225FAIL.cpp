#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring> 
#include <algorithm> 
using namespace std;  

#define MOD 1000000000
int N,K; 
int memo[201][201];  

int chooseKSum(int k, int sum){
	if (memo[k][sum] != -1) return memo[k][sum];  
	if (k == 0 && sum == 0) return memo[k][sum] = 1;  
	memo[k][sum] = 0;  
	for (int i = 1; i <= N; i++){
		if (sum-i >= 0 && k-1 >= 0){
			memo[k][sum] += chooseKSum(k-1,sum-i);  
			memo[k][sum] %= MOD;  
		}
	}
	return memo[k][sum]; 
}

int main(){
	scanf("%d %d",&N,&K);  
	memset(memo,-1,sizeof(memo));  
	int ans = chooseKSum(K,N);  
	if (K == 1){
		printf("1\n"); 
	}else{
		printf("%d\n", N == 1 ? ans : ans+K);  
	}
	return 0; 
}	

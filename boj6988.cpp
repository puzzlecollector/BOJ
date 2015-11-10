/*
Problem Link: https://www.acmicpc.net/problem/6988
DP problem: solution using O(n^2) algorithm. 
We have the sequence s[1],s[2],...,s[n], and define T[i][j] to be the maximum value 
that has i and j as the two starting values of the arithmetic sequence. 
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std; 

int dp[3001][3001];  
int s[3001];  
int chk[1000005];
int n,maxi,d; 

int main(){
	int n; 
	scanf("%d",&n); 
	for (int i = 0; i < n; i++){
		scanf("%d",&s[i]);  
	}
	for (int i = 0; i < n; i++){
		chk[s[i]] = i+1;  
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < i; j++){
			d = s[i]-s[j]; 
			if (s[j]-d >= 0 && chk[s[j]-d] > 0){
				int k = chk[s[j]-d]-1; 
				if (dp[j][k] > 0){
					dp[i][j] = s[i] + dp[j][k]; 
				}else{
					dp[i][j] = s[i]+s[j]+s[k]; 
				}
			}
			if (dp[i][j] > maxi){
				maxi = dp[i][j]; 
			}
		}
	}
	printf("%d\n",maxi); 
	return 0; 
}

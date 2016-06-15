#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <algorithm> 
#include <cmath> 
using namespace std; 

bool isPrime(int n){
	if (n <= 1) return false;  
	for (int i = 2; i*i <= n; i++){
		if (n%i == 0) return false; 
	}
	return true; 
}

double dp[20][20][20]; // dp[p][a][b]: 구간 p에서 점수가 a,b일 확률.  

int main(){
	double pa,pb; 
	scanf("%lf %lf",&pa,&pb); 
	pa /= 100, pb /= 100;  
	dp[1][0][0] = (1-pa)*(1-pb);  
	dp[1][1][0] = pa*(1-pb); 
	dp[1][0][1] = (1-pa)*pb;   
	dp[1][1][1] = pa*pb;  
	for (int p = 2; p <= 18; p++){
		for (int a = 0; a <= 18; a++){
			for (int b = 0; b <= 18; b++){
				dp[p][a][b] = (1-pa)*(1-pb)*dp[p-1][a][b]; // no scoring  
				if (a > 0) dp[p][a][b] += pa*(1-pb)*dp[p-1][a-1][b]; // a scoring
				if (b > 0) dp[p][a][b] += (1-pa)*pb*dp[p-1][a][b-1]; // b scoring
				if (a > 0 && b > 0) dp[p][a][b] += pa*pb*dp[p-1][a-1][b-1]; // both a,b scoring.  
			}
		}
	}
	double ans = 0.0;  
	for (int i = 0; i <= 18; i++){
		for (int j = 0; j <= 18; j++){
			if (isPrime(i) || isPrime(j)){
				ans += dp[18][i][j]; 
			}
		}
	}
	printf("%.16lf\n",ans); 
	return 0; 
}

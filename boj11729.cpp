#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
using namespace std; 

long long dp[21];

void moveDisk(char from, char to){
	printf("%c %c\n",from,to);  
}

void hanoi(int n, char from, char to, char aux){
	if (n == 1){
		moveDisk(from,to);  
		return; 
	}
	hanoi(n-1,from,aux,to);  
	moveDisk(from,to); 
	hanoi(n-1,aux,to,from);  
} 

int main(){
	dp[1] = 1; 
	dp[2] = 3;  
	for (int i = 3; i <= 20; i++){
		dp[i] = 2*dp[i-1]+1;  
	}
	int n; 
	scanf("%d",&n);    
	printf("%lld\n",dp[n]);  
	hanoi(n,'1','3','2'); 
	return 0; 
}

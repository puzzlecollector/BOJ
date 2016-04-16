#include <iostream> 
#include <cstdio> 
#include <algorithm> 
using namespace std; 

int dp[1000001];  
int a[1000001]; 

int main(){
	int n; 
	scanf("%d",&n);  
	for (int i = 0; i < n; i++){
		scanf("%d",&a[i]);  
	}
	int res = n; 
	for (int i = 0; i < n; i++){
		dp[a[i]] = dp[a[i]-1]+1; 
		res = min(res,n-dp[a[i]]); 
	}
	printf("%d\n",res); 
	return 0;    
}

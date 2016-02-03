#include <cstdio> 
#include <cstring> 
#include <cstdlib> 
using namespace std;  

#define MOD 1000000

char str[5005]; 
int dp[5005];  

int main(){
	scanf("%s",str);  
	dp[0]=dp[1]=1; 
	for (int i = 1; i < strlen(str); i++){
		if (str[i] == '0'){
			dp[i+1] = dp[i-1] ; 
		}else{
			if (str[i]-'0' + (str[i-1]-'0')*10 <= 26 && str[i-1] != '0'){
				dp[i+1] = (dp[i]%MOD + dp[i-1]%MOD)%MOD;  
			}else{
				dp[i+1] = dp[i];  
			}
		}
	}
	printf("%d\n",dp[strlen(str)]);  
	return 0;  
}

// Variation of the coin change problem 
#include <iostream>
#include <cstdio> 
#include <cstdlib>
using namespace std;  
 
int dp[10001],p,n,num,t;  
 
int main(){
    int last = 0; 
    dp[0] = 1;  
    scanf("%d",&t);  
    scanf("%d",&num);  
    for (int i = 0; i < num; i++){
        scanf("%d%d",&p,&n);
        for (int j = last; j >= 0; j--){
            for (int k = 1; k <= n; k++){
                if (j + p*k > t) break; 
                dp[j+k*p] += dp[j];  
            }
        }
        last += p*n;  
        if (last > t) last = t;  
    }
    printf("%d\n",dp[t]);  
    return 0; 
}

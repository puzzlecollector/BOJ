// Problem link: https://www.acmicpc.net/problem/10571
// Application of Longest Increasing Subsequence (LIS) 
// I translated this problem to Korean in Baekjoon Online Judge ^^ 
// Blog post: http://blog.naver.com/programmer18/220487137836
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <utility>
using namespace std; 
 
#define MAXN 201
 
pair<double,double> a[MAXN]; 
int dp[MAXN]; 
 
int main(){
    int t,n;
    double w,c;  
    scanf("%d",&t);  
    while (t--){
        scanf("%d",&n); 
        for (int i = 0; i < n; i++){
            scanf("%lf%lf",&a[i].first,&a[i].second); 
        }
        int res = 0; 
        for (int i = 0; i < n; i++){
            dp[i] = 1; 
            for (int j = 0; j < i; j++){
                if (a[j].first < a[i].first && a[j].second > a[i].second){
                    dp[i] = max(dp[i],dp[j]+1); 
                }
            }
            res = max(res,dp[i]); 
        } 
        printf("%d\n",res); 
    }    
    return 0; 
}

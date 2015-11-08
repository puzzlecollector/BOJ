// Problem Link: https://www.acmicpc.net/problem/7453
// Cannot use O(n^4) brute force. Divide the list into A,B,C and D and use binary search 
// that runs in time complexity O(n^2lgn)
// blog post: http://blog.naver.com/programmer18/220492954864
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std; 
 
#define MAXN 4005
typedef long long ll; 
 
int n;  
int A[MAXN],B[MAXN],C[MAXN],D[MAXN];
 
int CD[MAXN*MAXN];  // C,D에서 추출하는 방법의 갯수 
 
void solve(){
    // C와 D부터 추출하는 방법의 전열거 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            CD[i*n + j] = C[i] + D[j]; 
        }
    }
    sort(CD,CD+n*n);  
    ll res = 0; 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int cd = -(A[i] + B[j]);  
            // C,D로부터 합이 cd가 되도록 추출 
            res += upper_bound(CD,CD + n*n, cd) - lower_bound(CD, CD + n*n, cd); 
        }
    }
    printf("%lld\n",res);  
}
 
int main(){
    scanf("%d",&n);  
    for (int i = 0; i < n; i++){
        scanf("%d%d%d%d",&A[i],&B[i],&C[i],&D[i]);  
    }
    solve(); 
    return 0; 
}


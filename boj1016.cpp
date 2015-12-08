/*
Problem Link: https://www.acmicpc.net/problem/1016
*/ 
#include <iostream> 
#include <cstdlib>
#include <algorithm> 
#include <climits> 
#include <cmath> 
#include <cstdio>
#include <cstring> 
using namespace std; 
 
typedef long long ll;  
const ll m = 1000005;  
bool flag[m]; 
ll p[m],u[m],i,j,k,n,test; 
void init()
{
    ll i,j,k; 
    memset(flag,0,sizeof(flag)); 
    test = 0; 
    for (i = 2, u[1]=1; i < m; ++i){
        if (!flag[i]) p[++test] = i, u[i] = -1;  
        for (j = 1; j <= test; ++j){
            k = i*p[j];  
            if (k >= m) break;  
            flag[k] = 1;  
            if (i%p[j] == 0){
                u[k] = 0; 
                break; 
             }
             u[k] = -u[i];  
        }
    }
}
 
ll get(ll x)
{
    ll i,t,res = 0;  
    for (i = 1, t = floor(sqrt(x)); i <= t; ++i) res += u[i]*(x/(i*i));  
    return res; 
} 
 
bool isNNnum(ll n)
{
    for (ll i = 2; i*i <= n; ++i)
    {
        if (n % (i*i) == 0){
            return false; // 제곱 ㄴㄴ수가 아니다. 
        }
    }
    return true; //제곱 ㄴㄴ수이다. 
}
 
int main(){
    init();  
    ll n,m; 
    cin >> n >> m;  
    if (n == m){
        if (isNNnum(n)){
            cout << 1 << endl;  // 제곱 ㄴㄴ 수이다. 
            return 0; 
        }
        else {
            cout << 0 << endl; // 제곱 ㄴㄴ 수가 아니다. 
            return 0; 
        }
    }  
    cout << get(m) - get(n-1) << endl; 
    return 0; 
}

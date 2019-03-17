#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
ll power(ll a,ll x){
  if (x == 0) return 1LL;
  if (x == 1) return a;
  return power(a,x/2)*power(a,x/2)*power(a,x%2);
}
int main(int argc,char **argv){
  ll n, ans = 0, exponent = 0;
  scanf("%lld",&n);
  while (n){
    if (n&1) ans += power(3LL,exponent);
    n >>= 1LL;
    exponent++;
  }
  return !printf("%lld\n",ans);
}

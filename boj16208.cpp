#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXN = 500005;
typedef long long ll;
ll a[MAXN];
int main(int argc,char **argv){
  int n;
  scanf("%d",&n);
  priority_queue< ll,vector<ll>,greater<ll> > pq;
  for (int i = 0; i < n; i++){
    scanf("%lld",&a[i]);
    pq.push(a[i]);
  }
  ll ans = 0;
  while (pq.size() > 1){
    ll x = pq.top(); pq.pop();
    ll y = pq.top(); pq.pop();
    ans += x*y;
    pq.push(x+y);
  }
  return !printf("%lld\n",ans);
}

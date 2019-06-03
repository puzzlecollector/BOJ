#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main(int argc,char **argv){
  typedef long long ll;
  ll X,Y,W,S;
  scanf("%lld %lld %lld %lld",&X,&Y,&W,&S);
  if (X < Y) swap(X,Y);
  ll mod = (X+Y)%2;
  ll ans = min(W*(X+Y),min((X-mod)*S + mod*W,Y*S + (X-Y)*W));
  printf("%lld\n",ans);
  return 0;
}

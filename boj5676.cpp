#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
const int MAXN = 1e5+5;
ll a[MAXN],tree[MAXN];
int N,K;
ll sum(int i){
  ll ret = 0;
  while (i > 0){
    ret += tree[i];
    i -= (i & -i);
  }
  return ret;
}
void update(int i,ll val){
  while (i <= N){
    tree[i] += val;
    i += (i & -i);
  }
}
int main(int argc,char **argv){
  IOFAST();
  while (cin >> N >> K){
    memset(tree,0,sizeof(tree));
    for (int i = 1; i <= N; i++){
      cin >> a[i];
      if (a[i] == 0){
        update(i,(ll)1e6);
      }else if (a[i] > 0){
        update(i,0LL);
      }else if (a[i] < 0){
        update(i,1LL);
      }
    }
    for (int i = 1; i <= K; i++){
      char c;
      int x,y;
      cin >> c >> x >> y;
      if (c == 'P'){
        ll ans = sum(y)-sum(x-1);
        if (ans >= (ll)1e6) cout << '0';
        else if (ans&1) cout << '-';
        else cout << '+';
      }else if (c == 'C'){
        ll diff = (y > 0 ? 0 : y < 0 ? 1 : 1e6)-(a[x] > 0 ? 0 : a[x] < 0 ? 1 : 1e6);
        a[x] = y; 
        update(x,diff);
      }
    }
    cout << "\n";
  }
  return 0;
}

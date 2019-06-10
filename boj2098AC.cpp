#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MAXN = 17;
const ll INF = 1e10;
ll W[MAXN][MAXN];
ll cache[(1<<MAXN)][MAXN];
int n;
ll solve(int S,int v){
  if (S == (1<<n)-1 && v == 0){
    return 0;
  }
  ll &ret = cache[S][v];
  if (ret != -1) return ret;
  ret = INF;
  for (int u = 0; u < n; u++){
    if (!(S & (1<<u)) && ((v != u && W[v][u] > 0) || v == u)){
      ret = min(ret,solve(S|1<<u,u)+W[v][u]);
    }
  }
  return ret;
}
int main(int argc,char **argv){
  cin >> n;
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      cin >> W[i][j];
    }
  }
  memset(cache,-1,sizeof(cache));
  ll ans = solve(0,0);
  cout << ans << endl;
  return 0;
}

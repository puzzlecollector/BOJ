#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
ll cache[128][64];
int n,k,start;
// we start at n, then if we reach n+k we are dead
ll solve(int pos,int move){
  if (pos >= start+k) return 0; // dead
  if (move == 0) return 1; // we used up all our turns and we are not dead yet
  ll &ret = cache[pos][move];
  if (ret != -1) return ret;
  return ret = solve(pos-1,move-1)+solve(pos+1,move-1);
}
int main(int argc,char **argv){
  cin >> k >> n;
  memset(cache,-1,sizeof(cache));
  start = n;
  ll ans = solve(n,n);
  cout << ans << "\n";
  return 0;
}

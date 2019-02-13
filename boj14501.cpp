#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 20;
int T[MAXN],P[MAXN];
int N;
int cache[MAXN]; // values initialized to -1
int solve(int i){
  if (i > N){
    return 0;
  }
  int &ret = cache[i];
  if (ret != -1) return ret;
  if (i+T[i] <= N+1){
    ret = solve(i+T[i])+P[i];
  }
  return ret = max(ret,solve(i+1));
}
int main(int argc,char **argv){
  scanf("%d",&N);
  for (int i = 1; i <= N; i++){
    scanf("%d %d",&T[i],&P[i]);
  }
  memset(cache,-1,sizeof(cache));
  int ans = solve(1);
  printf("%d\n",ans);
  return 0;
}

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int mod = 1e9+9;
const int MAXN = 100005;
int cache[MAXN][4];
int solve(int n,int previous){
  if (n == 0) return 1;
  int &ret = cache[n][previous];
  if (ret != -1) return ret;
  ret = 0;
  for (int i = 1; i <= 3; i++){
    if (i != previous && n-i >= 0){
      ret = (ret%mod + solve(n-i,i)%mod)%mod;
    }
  }
  return ret;
}
int main(int argc,char **argv){
  int t;
  scanf("%d",&t);
  memset(cache,-1,sizeof(cache));
  while (t--){
    int n;
    scanf("%d",&n);
    printf("%d\n",solve(n,0));
  }
  return 0;
}

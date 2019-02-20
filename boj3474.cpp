#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int main(int argc,char **argv){
  int T;
  scanf("%d",&T);
  while (T--){
    int N,ans = 0;
    scanf("%d",&N);
    long long l = 5LL;
    while (l <= N){
      ans += N/l;
      l *= 5LL;
    }
    printf("%d\n",ans);
  }
  return 0;
}

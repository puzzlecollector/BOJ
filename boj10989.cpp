#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int cnt[10001];
int main(){
  int N, maxn = -1;
  scanf("%d",&N);
  for (int i = 0; i < N; i++){
    int x;
    scanf("%d",&x);
    cnt[x]++;
    maxn = max(maxn, x);
  }
  for (int i = 1; i <= maxn; i++){
    for (int j = 0; j < cnt[i]; j++){
      printf("%d\n",i);
    }
  }
  return 0;
}

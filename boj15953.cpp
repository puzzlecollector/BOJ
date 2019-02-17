#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int first[6] = {5000000,3000000,2000000,500000,300000,100000};
int second[5] = {5120000,2560000,1280000,640000,320000};
int main(int argc,char **argv){
  int t;
  scanf("%d",&t);
  while (t--){
    int a,b,ans = 0;
    scanf("%d %d",&a,&b);
    if (a == 1) ans += first[0];
    else if (a >= 2 && a <= 3) ans += first[1];
    else if (a >= 4 && a <= 6) ans += first[2];
    else if (a >= 7 && a <= 10) ans += first[3];
    else if (a >= 11 && a <= 15) ans += first[4];
    else if (a >= 16 && a <= 21) ans += first[5];
    if (b == 1) ans += second[0];
    else if (b >= 2 && b <= 3) ans += second[1];
    else if (b >= 4 && b <= 7) ans += second[2];
    else if (b >= 8 && b <= 15) ans += second[3];
    else if (b >= 16 && b <= 31) ans += second[4];
    printf("%d\n",ans);
  }
  return 0;
}

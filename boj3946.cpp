#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
double cache[1005][1005];
double L,R;
double solve(int n,int f){
  if (n == 0) return f;
  double &ret = cache[n][f];
  if (ret != -1.0) return ret;
  double E0 = solve(n-1,f);
  double EL = solve(n-1,f+1)-1.0;
  double ER = solve(n-1,max(0,f-1))+1.0;
  return ret = E0*(1-L-R)+EL*L+ER*R;
}
int main(int argc,char **argv){
  IOFAST();
  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n >> L >> R;
    for (int i = 0; i < 1005; i++){
      for (int j = 0; j < 1005; j++){
        cache[i][j] = -1.0;
      }
    }
    double ans = solve(n,0);
    cout.setf(ios::fixed);
    cout.precision(4);
    cout << ans << "\n";
  }
  return 0;
}

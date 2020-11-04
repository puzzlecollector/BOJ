#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
int S;
int cache[2002][2002];
const int INF = 1e9;
int solve(int paste_cnt, int current){
  if (current == S){
    return 0; // we are done
  }
  int &ret = cache[paste_cnt][current];
  if (ret != -1) return ret;
  ret = INF;
  if (paste_cnt > 0 && current <= S){ // paste
    ret = min(ret,solve(paste_cnt,current+paste_cnt)+1);
  }
  if (current >= 1){ // copy
    ret = min(ret,solve(current, current)+1);
  }
  if (current-1 >= 1){ // delete
    ret = min(ret,solve(paste_cnt,current-1)+1);
  }
  return ret;
}
int main(){
  cin >> S;
  memset(cache,-1,sizeof(cache));
  int ans = solve(0,1);
  cout << ans << "\n";
  return 0;
}

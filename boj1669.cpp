#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main(int argc,char **argv){
  IOFAST();
  ll X,Y;
  cin >> X >> Y;
  ll D = Y-X;
  ll k = 1;
  if (D == 0){
    cout << 0 << "\n";
    return 0;
  }
  if (D == 1 || D == 2 || D == 3){
    cout << 1 << "\n";
    return 0;
  }
  while (k*k < D){
    k++;
  }
  if (k*k == D){
    cout << 2*k-1 << "\n";
  }else if (k*k > D){
    // D must be in between (k-1)*(k-1) and k*k
    if (D-(k-1)*(k-1) <= (k-1)){
      cout << 2*k-2 << "\n";
    }else{
      cout << 2*k-1 << "\n";
    }
  }
  return 0;
}

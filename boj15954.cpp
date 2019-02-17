#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
double a[505];
double psum[505];
int main(int argc,char **argv){
  double N,K,sum = 0;
  cin >> N >> K;
  for (int i = 1; i <= N; i++){
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 1; i <= N; i++){
    psum[i] = psum[i-1]+a[i];
  }
  double min_sd = 1e9;
  for (int i = 1; i <= N; i++){
    for (int j = K; i+j-1 <= N; j++){
      double var = 0;
      double avg = (psum[i+j-1]-psum[i-1])/j;
      for (int x = i; x <= i+j-1; x++){
        var += (a[x]-avg)*(a[x]-avg);
      }
      var /= j;
      double sd = sqrt(var);
      min_sd = min(min_sd,sd);
    }
  }
  cout.setf(ios::showpoint);
  cout.setf(ios::fixed);
  cout.precision(11);
  cout << min_sd << endl;
  return 0;
}

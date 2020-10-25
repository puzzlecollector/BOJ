#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

double p[2][2];
double cache_good[2][101];
double cache_bad[2][101];

double solve_good(int mood, int day){
  if (day == 0 && mood == 0){
    return 1.0;
  }else if (day == 0 && mood == 1){
    return 0.0;
  }
  double &ret = cache_good[mood][day];
  if (ret != -1.0) return ret;
  return ret = p[mood][0]*solve_good(0,day-1) + p[mood][1]*solve_good(1,day-1);
}

double solve_bad(int mood, int day){
  if (day == 0 && mood == 1){
    return 1.0;
  }else if (day == 0 && mood == 0){
    return 0.0;
  }
  double &ret = cache_bad[mood][day];
  if (ret != -1.0) return ret;
  return ret = p[mood][0]*solve_bad(0,day-1) + p[mood][1]*solve_bad(1,day-1);
}

int main(){
  int N,mood;
  cin >> N >> mood;
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 2; j++){
      cin >> p[i][j];
    }
  }
  for (int i = 0; i < 2; i++){
    for (int j = 0; j < 101; j++){
      cache_good[i][j] = -1;
      cache_bad[i][j] = -1;  
    }
  }
  double good = solve_good(mood, N);
  double bad = solve_bad(mood,N);
  cout << int(good*1000) << "\n";
  cout << int(bad*1000) << "\n";
}

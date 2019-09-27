#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <set>
using namespace std;
typedef pair<int,int> P;
P points[5005];
set<P> exists;
int main(int argc,char **argv){
  int N;
  cin >> N;
  for (int i = 0; i < N; i++){
    cin >> points[i].first >> points[i].second;
    exists.insert(points[i]);
  }
  int cnt = 0;
  for (int i = 0; i < N; i++){
    for (int j = i+1; j < N; j++){
      if (points[i].first != points[j].first &&
        points[i].second != points[j].second && exists.count(P(points[i].first,points[j].second)) &&
      exists.count(P(points[j].first,points[i].second))){
        cnt++;
      }
    }
  }
  cout << cnt/2 << "\n";
  return 0;
}

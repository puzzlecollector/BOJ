#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
using namespace std;
int main(){
  string s;
  int n;
  cin >> n;
  map<string,int> mp;
  for (int i = 0; i < n; i++){
    cin >> s;
    mp[s]++;
  }
  for (int i = 0; i < n-1; i++){
    cin >> s;
    if (mp[s] > 0){
      mp[s]--;
    }
    if (mp[s] == 0){
      mp.erase(s);
    }
  }
  cout << mp.begin()->first << "\n";
  return 0;
}

// O(NQ)
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <set>
using namespace std;
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main(int argc,char **argv){
  IOFAST();
  int n;
  cin >> n;
  for (int t = 1; t <= n; t++){
    int s,q,cnt = 0;
    cin >> s;
    string str;
    cin.ignore();
    for (int i = 0; i < s; i++){
      getline(cin,str);
    }
    set<string> st;
    cin >> q;
    cin.ignore();
    for (int i = 0; i < q; i++){
      getline(cin,str);
      if (!st.count(str)){
        st.insert(str);
      }
      if (st.size() == s){
        cnt++;
        st.clear();
        st.insert(str);
      }
    }
    cout << "Case #" << t << ": " << cnt << "\n";
  }
  return 0;
}

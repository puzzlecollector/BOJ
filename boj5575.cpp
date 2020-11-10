#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc,char **argv){
  int h1,m1,s1,h2,m2,s2;
  for (int i = 0; i < 3; i++){
    cin >> h1 >> m1 >> s1 >> h2 >> m2 >> s2;
    // calculate seconds
    if (s1 > s2){
      if (m2 > 0){
        m2--;
        s2 += 60;
        s2 -= s1;
      }else if (h2 > 0){
        h2--;
        m2 += 59;
        s2 += 60;
        s2 -= s1;
      }
    }else{
      s2 -= s1;
    }
    // calculate minutes
    if (m1 > m2){
      h2--;
      m2 += 60;
      m2 -= m1;
    }else{
      m2 -= m1;
    }
    // take care of hours
    h2 -= h1;
    if (h2 < 0){
      h2 += 12;
    }
    cout << h2 << " " << m2 << " " << s2 << "\n";
  }
}

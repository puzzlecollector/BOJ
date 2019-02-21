#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
using namespace std;
stack<int> s[7];
int main(){
  int n,p,cnt = 0;
  scanf("%d %d",&n,&p);
  for (int i = 0; i < n; i++){
    int x,y;
    scanf("%d %d",&x,&y);
    while (!s[x].empty() && s[x].top() > y){
      cnt++;
      s[x].pop();
    }
    if (s[x].empty() || s[x].top() < y){
      cnt++;
      s[x].push(y);
    }
  }
  return !printf("%d\n",cnt); 
}

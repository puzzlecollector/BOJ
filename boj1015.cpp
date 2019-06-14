#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <map>
#include <queue> 
using namespace std;
const int MAXN = 55;
const int MAXA = 1005;
int a[MAXN],c[MAXN];
int main(int argc,char **argv){
  int n;
  scanf("%d",&n);
  for (int i = 0; i < n; i++){
    scanf("%d",&a[i]);
    c[i] = a[i];
  }
  sort(c,c+n);
  map<int,priority_queue< int,vector<int>,greater<int> > > pos;
  for (int i = 0; i < n; i++){
    pos[c[i]].push(i);
  }
  for (int i = 0; i < n; i++){
    int k = pos[a[i]].top();
    pos[a[i]].pop();
    printf("%d%c",k,i == n-1 ? '\n' : ' ');
  }
  return 0;
}

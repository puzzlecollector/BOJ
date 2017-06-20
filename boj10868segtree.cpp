// We have N integers, find minimum value in range [a,b].
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = LLONG_MAX;
ll init(vector<ll> &a,vector<ll> &tree,int node,int start,int end){ // we should set the values of tree[node].
  if (start == end) return tree[node] = a[start]; // in the leaf node, the element of array itself is stored.
  return tree[node] = min(init(a,tree,node*2,start,(start+end)/2),init(a,tree,node*2+1,(start+end)/2+1,end));
}
ll query(vector<ll> &tree,int node,int start,int end,int left,int right){ // find the min value in range [left,right]
  if (end < left || start > right) return INF;
  if (left <= start && end <= right) return tree[node];
  return min(query(tree,node*2,start,(start+end)/2,left,right),query(tree,node*2+1,(start+end)/2+1,end,left,right));
}
void update(vector<ll> &tree,int node,int start,int end,int index,ll diff){
  if (index < start || index > end) return;
  tree[node] = tree[node]+diff;
  if (start != end){ // if not leaf node, change for all of its children
    update(tree,node*2,start,(start+end)/2,index,diff);
    update(tree,node*2+1,(start+end)/2+1,end,index,diff);
  }
}
int main(){
  //ios_base::sync_with_stdio(false);
  //cin.tie(0); cout.tie(0);
  int n,m;
  scanf("%d %d",&n,&m);
  vector<ll> a(n);
  for (int i = 0; i < n; i++){
    scanf("%lld",&a[i]);
  }
  int h = ceil(log2(n)); // the height of the tree is ceil(log2(n)), where n is the number of nodes.
  int seg_tree_size = (1<<(h+1));
  vector<ll> tree(seg_tree_size);
  init(a,tree,1,0,n-1);
  while (m--){
    int a,b;
    scanf("%d %d",&a,&b);
    a--,b--;
    ll ans = query(tree,1,0,n-1,a,b);
    printf("%d\n",ans);
  }
  return 0;
}

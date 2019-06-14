#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vec;
typedef vector<vec> mat;
typedef long long ll;
const int MOD = 1000;
// multiplies two matrixes
mat mul(mat &A,mat &B){
  mat C(A.size(),vec(B[0].size()));
  for (int i = 0; i < A.size(); i++){
    for (int k = 0; k < B.size(); k++){
      for (int j = 0; j < B[0].size(); j++){
        C[i][j] = (C[i][j] + A[i][k]*B[k][j])%MOD;
      }
    }
  }
  return C;
}
// raise matrix A to the nth power
mat pow(mat A,ll n){
  mat B(A.size(),vec(A.size()));  // identity matrix
  for (int i = 0; i < A.size(); i++){
    B[i][i] = 1;
  }
  while (n > 0){
    if (n&1) B = mul(B,A);
    A = mul(A,A);
    n >>= 1;
  }
  return B;
}
// Solves the matrix power sum problem
ll n,k; // dimension of the matrix, sum to the power of k
mat A;
void solve(){
  mat B(n*2,vec(n*2));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      B[i][j] = A[i][j];
    }
    B[n+i][i] = B[n+i][n+i] = 1;
  }
  B = pow(B,k+1);
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      int a = B[n+i][j]%MOD;
      if (i == j) a = (a+MOD-1)%MOD;
      printf("%d%c",a,(j < n-1 ? ' ' : '\n'));
    }
  }
}
int main(int argc,char **argv){
  scanf("%d %lld",&n,&k);
  A.resize(n,vec(n));
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      scanf("%d",&A[i][j]);
    }
  }
  solve();
  return 0;
}

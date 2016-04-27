#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstdlib> 
#include <cmath>
using namespace std;  

#define INF 100100
#define MAXN 10001

double L[MAXN];  
int N,K;  

bool chk(double x){
	int num = 0; 
	for (int i = 0; i < N; i++){
		num += (int)(L[i]/x); 
	}
	return num >= K;  
}

int main(){
	scanf("%d %d",&N,&K);  
	for (int i = 0; i < N; i++){
		scanf("%lf",&L[i]); 
	}
	double lb = 0, ub = INF; 
	while (ub-lb > 1e-5){
		double mid = (lb+ub)/2; 
		if (chk(mid)) lb = mid;  
		else ub = mid; // num < K라는 뜻: mid 가 더 작아져야한다는 뜻 -> ub = mid; 
	}
	printf("%.2f\n",floor(ub*100)/100);  // ub < 1이라면 0.00출력. 
	return 0;  
}

#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
using namespace std;  

#define MAXM 1111 

struct triplet{
	int start, end, eff; 
}; 

int dp[MAXM]; 
triplet cow[MAXM]; 
int N,M,R; 

bool cmp(triplet t1, triplet t2){
	return t1.end < t2.end;  
}

int main(){
	cin >> N >> M >> R; 
	for (int i = 0; i < M; i++){
		cin >> cow[i].start >> cow[i].end >> cow[i].eff; 
	}
	sort(cow,cow+M,cmp); 
	for (int i = 0; i < M; i++){
		dp[i] = cow[i].eff; 
	}
	for (int i = 0; i < M; i++){
		for (int j = i+1; j < M; j++){
			if (cow[j].start >= cow[i].end+R){
				dp[j] = max(dp[j],dp[i]+cow[j].eff);   
			}
		}
	}
	int res = 0; 
	for (int i = 0; i < M; i++){
		res = max(res,dp[i]); 
	}
	cout << res << endl;
	return 0; 
}

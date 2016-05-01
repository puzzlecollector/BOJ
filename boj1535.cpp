// variation of the knapsack problem 
#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <algorithm> 
using namespace std; 

#define MAXN 21

int n,hp = 100;
int exhaust[MAXN],happiness[MAXN];    

int rec(int i, int j){
	// i번째 이후의 체력의 총합이 j 이하가 되도록 고른다. 
	int res; 
	if (i == n){
		res = 0;  
	}else if (j <= exhaust[i]){
		res = rec(i+1,j);  
	}else{
		res = max(rec(i+1,j),rec(i+1,j-exhaust[i])+happiness[i]);  
	}
	return res; 
}

int main(){
	scanf("%d",&n); 
	for (int i = 0; i < n; i++){
		scanf("%d",&exhaust[i]);  
	}
	for (int i = 0; i < n; i++){
		scanf("%d",&happiness[i]); 
	}
	int ans = rec(0,hp);  
	printf("%d\n",ans); 
	return 0; 
}

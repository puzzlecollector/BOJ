#include <iostream>
#include <cstdlib> 
#include <cstdio> 
#include <algorithm> 
using namespace std; 

#define MAXN 401 
#define INF 987654321
int n,k,s,a,b;  
int relation[MAXN][MAXN];  

void init(){
	for (int i = 0; i < MAXN; i++){
		for (int j = 0; j < MAXN; j++){
			if (i == j) relation[i][j] = 0; 
			else relation[i][j] = INF; 
		}
	}
}

int main(){
	init();  
	scanf("%d %d",&n,&k);   
	for (int i = 0; i < k; i++){
		scanf("%d %d",&a,&b); 
		--a,--b;  
		relation[a][b] = 1;  
	}
	//floyd-warshall 
	for (int k = 0; k < n; k++){
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				relation[i][j] = min(relation[i][j],relation[i][k]+relation[k][j]);  
			}
		}
	}
	// getting input 
	scanf("%d",&s); 
	for (int i = 0; i < s; i++){
		scanf("%d %d",&a,&b); 
		--a,--b;  
		if (relation[a][b] != INF) cout << -1 << endl; 
		else if (relation[b][a] != INF) cout << 1 << endl; 
		else if (relation[a][b] == INF && relation[b][a] == INF) cout << 0 << endl; 
	}
	return 0; 
}

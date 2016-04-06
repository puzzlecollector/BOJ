#include <cstdio> 
#include <algorithm> 
#include <cstdlib> 
using namespace std; 

int grid[301][301];  
int minimax[301][301];  
#define INF 987654321

int main(){
	for (int i = 0; i < 301; i++){
		for (int j = 0; j < 301; j++){
			if (i == j) grid[i][j] = 0;  
			else grid[i][j] = INF;  
		}
	}
	int N,M,T; 
	scanf("%d %d %d",&N,&M,&T);  
	for (int i = 0; i < M; i++){
		int a,b,c;  
		scanf("%d %d %d",&a,&b,&c); 
		--a,--b; 
		grid[a][b] = c;  
	}
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			minimax[i][j] = grid[i][j];  
		}
	}
	for (int k = 0; k < N; k++){
		for (int i = 0; i < N; i++){
			for (int j = 0; j < N; j++){
				int path = max(minimax[i][k],minimax[k][j]);  
				if (path < minimax[i][j]){
					minimax[i][j] = path; 
				}	
			}
		}
	}
	for (int i = 0; i < T; i++){
		int a,b;
		scanf("%d %d",&a,&b);  
		--a,--b;  
		if (minimax[a][b] == INF) printf("-1\n"); 
		else printf("%d\n",minimax[a][b]);  
	}
	return 0; 
}

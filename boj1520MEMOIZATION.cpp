// using memoization. 
// Just a normal DFS solution creates TLE. 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring> 
using namespace std;
 
#define MAXM 505
#define MAXN 505 
 
typedef pair<int,int> P; 
int field[MAXM][MAXN]; 
int M,N;  // 가로, 세로의 크기 
int D[MAXM][MAXN]; 
 
// 이동 방향 벡터 
int dy[4] = {1,0,-1,0}, dx[4] = {0,1,0,-1}; 
 
int dfs(int ey, int ex){
    if (ey == 0 && ex == 0) return D[ey][ex] = 1; 
    if (D[ey][ex] != -1) return D[ey][ex];  
    D[ey][ex] = 0;  
    for (int i = 0; i < 4; i++){
        int ny = ey + dy[i], nx = ex + dx[i];  
        if (0 <= ny && ny < M && 0 <= nx && nx < N && field[ey][ex] < field[ny][nx]){
            D[ey][ex] += dfs(ny,nx);  
        }
    }
    return D[ey][ex];  
}
 
int main(){
    scanf("%d%d",&M,&N);  
    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            scanf("%d",&field[i][j]); 
        }
    }
    memset(D,-1,sizeof(D)); 
    printf("%d\n",dfs(M-1,N-1)); 
    return 0;  
}

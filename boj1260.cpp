// Problem Link: https://www.acmicpc.net/problem/1260
// comparing DFS and BFS  
// 깊이우선 탐색과 너비우선 탐색을 각각 구현한뒤에 둘의 출력 결과를 비교한다. 
#include <iostream>
#include <cstdio>  
#include <cstdlib>
#include <algorithm> 
#include <vector>  
#include <string.h> 
#include <queue> 
using namespace std; 

#define MAXV 1001 

int N,M,V,A,B; 
int rear,front; // 전단, 후단을 나타내는 변수 
int chk[MAXV]; // 방문여부 
int graph[MAXV][MAXV]; // 인접행렬   
int q[MAXV]; // 큐 역할을 한다. 

void init(){
	memset(chk,0,sizeof(chk)); 
}

void DFS(int node){
	chk[node] = 1;  // 정점 node방문했다고 표시  
	for (int i = 1; i <= N; i++){ // 정점 node와i가 연결되었고, 정점 i를 방문하지 않았다면 
		if (graph[node][i] == 1 && !chk[i]){
			printf("%d ",i); 
			DFS(i); // 재귀호출 
		}
	}
}  

void BFS(int node){
	chk[node] = 1; // 정점 node방문했다고 표시 
	q[rear++] = node; // 큐에 node삽입, 후단 1 증가 
	while (front < rear){ // 전단과 후단이 같으면 루프 종료 
		node = q[front++]; // 큐에 첫번째 있는 데이터 제외, 제외된 값을 가져오고,전단 1 증가 
		for (int i = 1; i <= N; i++){
			// 정점 node와 i가 만나고, 정점 i를 방문하지 않은 상태일 경우  
			if (graph[node][i] == 1 && !chk[i]){
				chk[i] = 1; 
				printf("%d ",i); 
				q[rear++] = i;  // 큐에 i를 삽입, 후단을 1증가시킴. 
			}
		}
	}
}

int main(){
	scanf("%d %d %d",&N,&M,&V); 
	for (int i = 0; i < M; i++){
		scanf("%d %d",&A,&B); 
		graph[A][B] = 1; 
		graph[B][A] = 1; 
	}
	// process DFS 
	printf("%d ",V); 
	DFS(V); 
	printf("\n");    
	init();
	// process BFS 
	printf("%d ",V); 
	BFS(V);  
	printf("\n"); 
	return 0; 
}

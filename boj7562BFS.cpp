// BFS practice problem. 
#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <queue> 
#include <cstdio>
#include <algorithm> 
using namespace std;  

int visited[305][305]; // to check wheter that position has been visited. 
int dy[8] = {-2,-2,-1,-1,1,1,2,2}; 
int dx[8] = {-1,1,-2,2,-2,2,-1,1};
int T,L; // test cases, lenght of chess board.  

typedef struct node{
	int y, x, steps;  
}Node;  

void BreathFirstSearch(int sy, int sx, int ey, int ex){
	if (sy == ey && sx == ex){
		cout << 0 << endl;
		return; 
	}
	Node temp;  
	queue<Node> q; 
	temp.x = sx; temp.y = sy; temp.steps = 0; 
	visited[sy][sx] = 1; 
	q.push(temp); 
	while (!q.empty()){
		temp.x = q.front().x;  
		temp.y = q.front().y;  
		temp.steps = q.front().steps; 
		q.pop();   
		if (temp.y == ey && temp.x == ex){
			cout << temp.steps << endl; 
			return;  
		}
		for (int i = 0; i < 8; i++){
			Node next; 
			next.y = temp.y+dy[i], next.x = temp.x+dx[i];  
			next.steps = temp.steps+1; 
			if (next.y >= 0 && next.y < L && next.x >= 0 && next.x < L && !visited[next.y][next.x]){
				visited[next.y][next.x] = 1; 
				q.push(next);  
			}
		}
	}
}

int main(){
	cin >> T; 
	for (int i = 0; i < T; i++){
		cin >> L; 
		memset(visited,0,sizeof(visited));  
		int sy,sx,ey,ex; 
		cin >> sy >> sx >> ey >> ex;  
		BreathFirstSearch(sy,sx,ey,ex); 
	}
	return 0; 
}

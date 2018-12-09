#include <iostream> 
#include <cstdlib>
#include <algorithm>
#include <vector> 
#include <queue> 
#include <set> 
using namespace std; 
const int MAX = 55; 
char grid[MAX][MAX]; 
bool visited[1<<6][MAX][MAX];  
int dx[4] = {1,0,-1,0};  
int dy[4] = {0,1,0,-1};  
typedef pair<int,int> P; 
typedef pair<P,P> PP; 
int sx,sy; // start coordinates 
int N,M; 
bool inRange(int x,int y){
	return x >= 0 && x < N && y >= 0 && y < M; 
} 
int update_key(int cur,char key){
	return cur | (1<<(key-'a'));  
}
int check(int cur,char door){
	return cur & (1<<(door-'A')); 
} 
int bfs(){
  	cin >> N >> M; 
  	for (int i = 0; i < N; i++){
	  for (int j = 0; j < M; j++){
	    cin >> grid[i][j];  
	    if (grid[i][j] == '0'){
	      sx = i; 
	      sy = j; 
	    }
	  }
	} 
	queue<PP> q; 
	q.push(PP(P(sx,sy),P(0,0)));  
	while (!q.empty()){
		PP p = q.front(); q.pop();  
		int x = p.first.first; 
		int y = p.first.second; 
		int steps = p.second.first; 
		int key = p.second.second; 
		if (visited[key][x][y]) continue;  
		visited[key][x][y] = true;  
		if (grid[x][y] == '1'){
		  return steps; 
		} 
		for (int i = 0; i < 4; i++){
			int nx = x+dx[i];  
			int ny = y+dy[i];  
			if (!inRange(nx,ny) || visited[key][nx][ny] || 
			    grid[nx][ny] == '#') continue; 
			if (grid[nx][ny] >= 'A' && grid[nx][ny] <= 'F'){
			  if (check(key,grid[nx][ny])){
				q.push(PP(P(nx,ny),P(steps+1,key)));
		          }
			  continue; 
			}
			int nkey = key; 
			if (grid[nx][ny] >= 'a' && grid[nx][ny] <= 'f'){
			  nkey = update_key(key,grid[nx][ny]); 
			} 
			q.push(PP(P(nx,ny),P(steps+1,nkey)));  
		}
	}
	return -1; // no path 

} 
int main(int argc,char **argv){
	cout << bfs() << "\n";  
	return 0;  
} 

#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm>
#include <queue>
#include <vector> 
using namespace std;  
#define x first 
#define y second 
const int INF = (int)2e9+88;  
int dx[4] = {1,0,-1,0}; 
int dy[4] = {0,1,0,-1}; 
int N,M;
typedef pair<int,int> point; 
point A1,A2,B1,B2; 
bool inRange(int X,int Y){
	return X >= 0 && X <= N && Y >= 0 && Y <= M; 
}
point previous[105][105]; 
int dist[105][105];  
int visited[105][105];  
int bfs(int sx,int sy,int gx,int gy,int t){
	queue<point> q; 
	q.push(point(sx,sy));  
	dist[sx][sy] = 0;  
	while (!q.empty()){
		point p = q.front(); q.pop();  
		int curx = p.x; 
		int cury = p.y; 
		for (int i = 0; i < 4; i++){
			int nx = curx+dx[i]; 
			int ny = cury+dy[i]; 
			if (inRange(nx,ny) && !visited[nx][ny] && dist[nx][ny] > dist[curx][cury]+1){
				dist[nx][ny] = dist[curx][cury]+1; 
				previous[nx][ny] = point(curx,cury); 
				q.push(point(nx,ny));  
			}
		}
	}
	if (dist[gx][gy] != INF && t){
		for (point p = point(gx,gy); p != point(-1,-1); p = previous[p.x][p.y]){
			visited[p.x][p.y] = 1;  
		}
	}
	return dist[gx][gy];  
}
int main(){
	cin >> N >> M;  
	cin >> A1.x >> A1.y; 
	cin >> A2.x >> A2.y; 
	cin >> B1.x >> B1.y;  
	cin >> B2.x >> B2.y; 
	for (int i = 0; i < 105; i++){
		for (int j = 0; j < 105; j++){
			dist[i][j] = INF; 
			previous[i][j] = point(-1,-1);  
		}
	}
	int ans = INF;  
	visited[B1.x][B1.y] = visited[B2.x][B2.y] = 1;  
	int len1 = bfs(A1.x,A1.y,A2.x,A2.y,1);  
	if (len1 != INF){
		for (int i = 0; i < 105; i++){
			for (int j = 0; j < 105; j++){
				dist[i][j] = INF;  
			}
		}
		visited[B1.x][B1.y] = visited[B2.x][B2.y] = 0;  
		int len2 = bfs(B1.x,B1.y,B2.x,B2.y,0);  
		ans = min(ans,len1+len2);  
	}
	for (int i = 0; i < 105; i++){
		for (int j = 0; j < 105; j++){
			visited[i][j] = 0; 
			dist[i][j] = INF;  
		}
	}
	visited[A1.x][A1.y] = visited[A2.x][A2.y] = 1;  
	len1 = bfs(B1.x,B1.y,B2.x,B2.y,1); 
	if (len1 != INF){
		for (int i = 0; i < 105; i++){
			for (int j = 0; j < 105; j++){
				dist[i][j] = INF; 
			}
		}
		visited[A1.x][A1.y] = visited[A2.x][A2.y] = 0; 
		int len2 = bfs(A1.x,A1.y,A2.x,A2.y,0);  
		ans = min(ans,len1+len2); 
	}
	if (ans >= INF) cout << "IMPOSSIBLE" << endl; 
	else cout << ans << endl; 
	return 0;  
}

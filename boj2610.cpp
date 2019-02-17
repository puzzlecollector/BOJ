#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>
using namespace std;
#define IOFAST() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const int MAXN = 105;
const int INF = 987654321;
int n,m;
int d[MAXN][MAXN];
int visited[MAXN];
vector<int> ans;
void dfs(int cur,int id,map<int, vector<int> > &groups){
  if (visited[cur]) return;
  visited[cur] = 1;
  groups[id].push_back(cur);
  for (int i = 1; i <= n; i++){
    if (d[cur][i] != INF && d[cur][i] != 0){
      dfs(i,id,groups);
    }
  }
}
void DEBUG(){
  for (int i = 1; i<= n; i++){
    for (int j = 1; j <= n; j++){
      cout << d[i][j] << " ";
    }
    cout << endl;
  }
}
void init(){
  for (int i = 1; i < MAXN; i++){
		for (int j = 1; j < MAXN; j++){
			if (i == j) d[i][j] = 0;
			else d[i][j] = INF;
		}
	}
}
int main(int argc,char **argv){
  IOFAST();
  cin >> n >> m;
  init();
  for (int i = 0; i < m; i++){
    int a,b;
    cin >> a >> b;
    d[a][b] = d[b][a] = 1;
  }
  map<int,vector<int> > groups;
  int idx = 0;
  for (int i = 1; i <= n; i++){
    if (!visited[i]){
      dfs(i,idx,groups);
      idx++;
    }
  }
  cout << idx << "\n";
  // floyd warshall algorithm
  for (int k = 1; k <= n; k++){
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
        d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
      }
    }
  }
  // DEBUG();
  // picking the leader
  for (int i = 0; i < idx; i++){
    vector<int> v = groups[i];
    int min_time = INF, leader = -1;
    for (int j = 0; j < v.size(); j++){
      int min_request_time = 0;
      for (int k = 0; k < v.size(); k++){
        if (v[j] != v[k] && d[v[j]][v[k]] != INF){
          min_request_time = max(min_request_time,d[v[j]][v[k]]);
        }
      }
      if (min_time > min_request_time){
        min_time = min_request_time;
        leader = v[j];
      }
    }
    ans.push_back(leader);
  }
  sort(ans.begin(),ans.end());
  for (int i = 0; i < ans.size(); i++){
    cout << ans[i] << "\n";
  }
  return 0;
}

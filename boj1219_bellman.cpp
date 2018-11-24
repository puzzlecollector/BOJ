#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <algorithm>
#include <vector> 
using namespace std;
typedef long long ll;   
const ll INF = (ll)1e17; 
struct edge{ int from,to,cost; }; 
int s,e,N,M;  
ll d[222]; 
ll money[222]; 
vector<edge> g; 
int main(){
	scanf("%d %d %d %d",&N,&s,&e,&M); 
	for (int i = 0; i < M; i++){
		edge e; 
		scanf("%d %d %d",&e.from,&e.to,&e.cost);  
		e.cost *= -1;  
		g.push_back(e); 
	}
	for (int i = 0; i < N; i++){
		scanf("%lld",&money[i]); 
	}
	for (int i = 0; i < N; i++){
		d[i] = -INF;  
	}
	d[s] = money[s]; 
	for (int i = 0; i < 2*N; i++){
		for (int j = 0; j < M; j++){
			if (d[g[j].from] == -INF) continue; 
			else if (d[g[j].from] == INF) d[g[j].to] = INF; // tend to infinity  
			else if (d[g[j].to] < d[g[j].from] + g[j].cost + money[g[j].to]){
				d[g[j].to] = d[g[j].from] + g[j].cost + money[g[j].to]; 
				if (i >= N-1) d[g[j].to] = INF;  
			}
		}
	}
	if (d[e] == -INF) puts("gg"); 
	else if (d[e] == INF) puts("Gee"); 
	else printf("%lld\n",d[e]); 
	return 0;  
}

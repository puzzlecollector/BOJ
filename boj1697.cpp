#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <algorithm> 
#include <queue> 
using namespace std; 

int visited[100005];  

int main(){
	int N,K,cnt = 0; 
	scanf("%d%d",&N,&K);  
	queue<int> q;  
	if (N == K){
		printf("%d\n",cnt); 
	}else{
		q.push(N); 
		bool found = false; 
		while (!q.empty() && !found){
			int t = q.size(); 
			++cnt; 
			while (t--){
				int pos = q.front(); q.pop(); 
				int move[3] = {pos-1,pos+1,2*pos};
				for (int i = 0; i < 3; i++){
					if (move[i] == K){
						found = true; 
						break; 
					}else if (move[i] >= 0 && move[i] <= 100000 && !visited[move[i]]){
						visited[move[i]] = 1; // mark that this point was visited. 
						q.push(move[i]);  
					}
				}
			}
		}
		printf("%d\n",cnt); 
	}
	return 0; 
}

#include <iostream>
#include <cstdlib>
#include <cmath> 
#include <cstring> 
#include <queue> 
#include <cstring> 
#include <utility> 
using namespace std; 

#define MAX 10000
#define P pair<int,int> 
#define mp make_pair 

int notPrime[MAX], visited[MAX];  

void eratos(){
	notPrime[0] = notPrime[1] = 1; // i.e. both 0 and 1 are not primes. 
	for (int i = 2; i*i <= MAX; i++){
		if (!notPrime[i]){
			// i.e. if i is prime 
			for (int j = 2*i; j <= MAX; j += i){
				notPrime[j] = 1; 
			}
		}
	}
}

int main(){
	eratos(); 
	int N; 
	cin >> N; 
	for (int i = 0; i < N; i++){
		int a,b,ans = -1;  
		cin >> a >> b; 
		queue<P> q; 
		memset(visited,0,sizeof(visited)); 
		q.push(mp(a,0));
		visited[a] = true; 
		while (!q.empty()){
			int u = q.front().first, v = q.front().second; q.pop();  
			if (u == b){
				ans = v; 
				break; 
			}
			for (int i = 1; i <= 1000; i *= 10){
				int rem = (u - ((u/i)%10)*i); 
				for (int j = 0; j <= 9; j++){
					if (i == 1000 && j == 0) continue; // because then we won't have a 4 digit number.
					int n = rem + j*i;  
					if (visited[n] || notPrime[n]) continue; 
					visited[n] = 1;  
					q.push(mp(n,v+1)); 
				}
			}
		}
		if (ans == -1) cout << "Impossible" << endl;
		else cout << ans << endl; 
	}		
	return 0; 
}

#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <algorithm> 
using namespace std;  

#define MAXN 200010 

int T;  
int a[MAXN],l[MAXN],r[MAXN],d[MAXN]; 
const int INF = 1<<30; 

int main(){
	scanf("%d",&T); 
	while (T--){
		int n; 
		scanf("%d",&n); 
		for (int i = 1; i <= n; i++){
			scanf("%d",&a[i]); 
		}
		l[1] = 1;  
		for (int i = 2; i <= n; i++){
			if (a[i] > a[i-1]) l[i] = l[i-1]+1;  
			else l[i] = 1;  
		}
		r[n] = 1;  
		for (int i = n-1; i >= 1; i--){
			if (a[i] < a[i+1]) r[i] = r[i+1]+1;  
			else r[i] = 1;  
		}
		int ans = 0;  
		fill(d+1,d+n+1,INF); 
		for (int i = 1; i <= n; i++){
			int len = (lower_bound(d+1,d+1+i,a[i]))-(d+1)+r[i]; 
			ans = max(len,ans); 
			d[l[i]] = min(a[i],d[l[i]]); 
		}
		printf("%d\n",ans); 
	}
	return 0;  
}

#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <cmath> 
#include <cstring> 
#include <algorithm> 
using namespace std; 

#define INF 2147483648

typedef long long ll;  

int main(){
	int t; 
	scanf("%d",&t); 
	while (t--){
		int x,y; 
		scanf("%d %d",&x,&y); 
		if (x == y) printf("0\n"); 
		else if (y-x == 1) printf("1\n"); 
		ll d = y-x;  
		ll limit = (int)sqrt(INF)+1; 
		for (ll i = 1; i <= limit ;i++){ 
			if (d > i*i && i*(i+1) >= d){ 
				printf("%lld\n",2*i); break; 
			}else if (d > i*(i+1) && (i+1)*(i+1) >= d){
				printf("%lld\n",2*i+1); break; 
			}
		}
	}
	return 0; 
}

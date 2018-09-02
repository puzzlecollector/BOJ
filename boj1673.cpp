#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstdio> 
using namespace std; 
int main(){
	long long n,k; 
	while (scanf("%lld %lld",&n,&k) == 2){
		long long ans = n, stamps = n;  
		while (stamps >= k){
			ans += stamps/k; 
			stamps = stamps%k + stamps/k;  
		} 
		printf("%lld\n",ans); 
	}
	return 0; 
}

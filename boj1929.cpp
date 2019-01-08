#include <cstdio>
using namespace std;  
int prime[1000005];  
void eratos(){
	for (int i = 0; i < 1000005; i++){
		prime[i] = 1; 
	}
	prime[0] = prime[1] = 0; 
	for (long long i = 2; i < 1000005; i++){
		if (prime[i]){
			for (long long j = i*i; j < 1000005; j += i){
				prime[j] = 0;  
			}
		}
	}
}
int main(){
	int M,N; 
	scanf("%d %d",&M,&N); 
	eratos(); 
	for (int i = M; i <= N; i++){
		if (prime[i]){
			printf("%d\n",i); 
		}
	}
	return 0; 
}

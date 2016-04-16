#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <queue> 
#include <vector> 
#include <climits> 
#include <algorithm> 
using namespace std;  

#define INF 1000000000000000

queue<long long> a[101]; // array of queues. 
int b[101]; // storing the actual value of the primes.  
int K,N; // find the Nth Humble Number

int main(){
	scanf("%d %d",&K,&N); 
	// get K prime numbers as input 
	for (int i = 0; i < K; i++){
		int prime; 
		scanf("%d",&prime);  
		a[i].push(prime);  // so that we have K queues numbered from 0~(K-1). 
		b[i] = prime;   
	}
	long long val;  
	for (int i = 0; i < N; i++){
		val = INF; 
		int idx = 0;  
		for (int j = 0; j < K; j++){
			long long tempval = (a[j].empty() ? INF : a[j].front());  
			if (val > tempval){
				val = tempval; 
				idx = j;  
			}
		}
		//cout << val << ' ' << idx << endl; 
		for (int j = 0; j < K; j++){
			if (j < idx){
				continue;  
			}else if (j == idx){
				a[j].pop();  
				a[j].push(val*b[j]); 
			}else{
				a[j].push(val*b[j]); 
			}
		}
	}
	printf("%lld\n",val); 
	return 0;  
}

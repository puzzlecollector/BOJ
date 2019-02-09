#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <cstdio> 
#include <algorithm>
#include <map> 
using namespace std;  
const int MAXN = 10005;  
int prime[MAXN];  
void eratos(){
	for (int i = 0; i < MAXN; i++){
		prime[i] = 1;  
	}
	prime[0] = prime[1] = 0;  
	for (int i = 2; i < MAXN; i++){
		if (prime[i]){
			for (long long j = i*i; j < MAXN; j += i){
				prime[j] = 0;  
			}
		}
	}
}
int main(int argc,char **argv){
	eratos();  
	int C; 
	scanf("%d",&C);  
	while (C--){
		int n; 
		scanf("%d",&n);  
		if (prime[n]){
			printf("%d 2\n",n);  
		}else{
			map<int,int> mp;  
			int input = n; 
			for (int i = 2; i*i <= n; i++){
				while (n%i == 0){
					n /= i;  
					mp[i]++;  
				}
			}
			if (n != 1) mp[n]++;  
			long long ans = 1LL; 
			for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
				ans *= (it->second + 1);  
			}
			printf("%d %lld\n",input,ans); 
		}
	}
	return 0;  
}

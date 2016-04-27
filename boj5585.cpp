#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <algorithm> 
using namespace std; 
 
int main(){
	int n; 
	scanf("%d",&n);  
	int val = 1000-n;  
	int cnt = 0;  
	int a[6] = {500,100,50,10,5,1}; 
	for (int i = 0; i < 6; i++){
		while (val >= a[i]){
			++cnt;  
			val -= a[i]; 
		}
	}
	printf("%d\n",cnt); 
	return 0; 
}

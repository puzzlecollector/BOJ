#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <algorithm> 
using namespace std; 

int n,a[1001];  

int main(){
	scanf("%d",&n);
	for (int i = 0; i < n; i++){
		scanf("%d",&a[i]);  
	} 
	int maxUphill = 0;  
	int i = 0; 
	int uphillDistance = 0; 
	while (i < n-1){
		if (a[i] < a[i+1]){
			uphillDistance += a[i+1]-a[i];  
			++i;  
		}else{
			maxUphill = max(maxUphill,uphillDistance);  
			uphillDistance = 0; 
			++i;  
		}
	}
	maxUphill = max(maxUphill,uphillDistance); 
	printf("%d\n",maxUphill);  
	return 0; 	
}

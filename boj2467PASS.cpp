#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <algorithm> 
#include <climits> 
#include <vector> 
using namespace std;  

int a[100001];
int N; 

int binarySearch(int l, int r, int find){
	int idx;  
	while (r - l >= 1){
		int mid = (l+r)/2; 
		if (a[mid] == find) return mid; 
		else if (a[mid] < find){
			l = mid+1; 
		}
		else{
			r = mid; 
		}
		idx = mid; 
	}
	return idx; 
}

int main(){
	scanf("%d",&N);
	for (int i = 0; i < N; i++){
		scanf("%d",&a[i]); 
	}  
	int closest = INT_MAX;  
	int pos1,pos2;  
	// O(nlog(n))
	for (int i = 0; i < N; i++){
		int pos = binarySearch(0,N,-a[i]); 
		if (i == pos) continue; 
		if (closest > abs(a[i]+a[pos])){
			closest = abs(a[i]+a[pos]); 
			if (a[i] < a[pos]){
				pos1 = i, pos2 = pos; 
			}else{
				pos1 = pos, pos2 = i; 
			}
		}
	}	
	printf("%d %d\n",a[pos1],a[pos2]); 
	return 0; 
}

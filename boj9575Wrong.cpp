// will try to get this correct when I have time later 
#include <iostream>
#include <cstdio> 
#include <cstdlib>
#include <algorithm> 
#include <cstring> 
using namespace std; 

int a[51],b[51],c[51]; 
bool noted[90001];  // initially all false. 

bool checkVal(int n){
	int orig = n;  
	bool exist5 = false, exist8 = false, existOther = false; 
	while (n){
		if (n%10 == 5) exist5 = true;  
		else if (n%10 == 8) exist8 = true;  
		else{
			existOther = true; 
			break; 
		}
		n /= 10;  
	}
	if (exist5 && exist8 && !existOther) return true; 
	else if (orig < 10 && exist5) return true; 
	else if (orig < 10 && exist8) return true;  
	return false; 
}

int main(){
	int t,k,l,m; 
	scanf("%d",&t); 
	for (int i = 0; i < t; i++){
		memset(noted,false,sizeof(noted)); 
		scanf("%d",&k); 
		for (int j = 0; j < k; j++){
			scanf("%d",&a[j]);  
		}
		scanf("%d",&l); 
		for (int j = 0; j < l; j++){
			scanf("%d",&b[j]); 
		}
		scanf("%d",&m);  
		for (int j = 0; j < m; j++){
			scanf("%d",&c[j]);  
		}
		// evaluate answer. 
		int cnt = 0;  
		for (int x = 0; x < k; x++){
			for (int y = 0; y < l; y++){
				for (int z = 0; z < m; z++){
					int sum = a[x]+b[y]+c[z];  
					if (noted[sum]){
						continue;  
					}else{
						noted[sum] = true; 
						if (checkVal(sum)){
							++cnt; 
						}
					}
				}
			}
		}
		printf("%d\n",cnt);  
	}		
	return 0; 
}

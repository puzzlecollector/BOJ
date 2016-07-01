#include <cstdio> 
#include <algorithm> 
#include <cstring> 
using namespace std; 

char s[41]; 
int d[41]; 
int n; 

int solve(int k){
	if (s[k] == '0') return 0; 
	if (k >= n-1) return 1; 
	if (d[k] != 0) return d[k];  
	d[k] = solve(k+1);  
	if (k+1 < n && (s[k]-'0')*10 + (s[k+1]-'0') <= 34) d[k] += solve(k+2);  
	return d[k];  
}

int main(){
	scanf("%s",s);  
	n = strlen(s);  
	printf("%d\n",solve(0));  
	return 0; 
}

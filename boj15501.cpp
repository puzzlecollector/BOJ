#include <iostream>
#include <cstdio> 
#include <cstdlib>
#include <algorithm>
#include <vector> 
#include <map> 
using namespace std; 
const int MAXN = 1000005;  
typedef pair<int,int> P; 
int a[MAXN],b[MAXN]; 
map<int,P> adjacent; 
bool chk1(int n,int idx){
	return P(b[(idx-1+n)%n],b[(idx+1)%n]) == adjacent[b[idx]]; 
}
bool chk2(int n,int idx){
	return P(b[(idx+1)%n],b[(idx-1+n)%n]) == adjacent[b[idx]]; 
}
int main(int argc,char **argv){
	int n; 
	scanf("%d",&n);  
	for (int i = 0; i < n; i++){
		scanf("%d",a+i); 
	}
	for (int i = 0; i < n; i++){
		adjacent[a[i]] = P(a[(i-1+n)%n],a[(i+1)%n]); 
	}
	for (int i = 0; i < n; i++){
		scanf("%d",b+i); 
	} 
	bool failed = false; 
	for (int i = 0; i < n; i++){
		if (!chk1(n,i)){
			failed = true; 
			break; 
		}
	}
	if (!failed){
		return !printf("good puzzle\n"); 
	}
	for (int i = 0; i < n; i++){
		if (!chk2(n,i)){
			return !printf("bad puzzle\n"); 
		}
	}
	printf("good puzzle\n");  
	return 0; 
}

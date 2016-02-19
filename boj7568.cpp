// Problem Link: https://www.acmicpc.net/problem/7568
#include <iostream>
#include <cstdio> 
#include <cstdlib> 
#include <cstring> 
#include <algorithm> 
#include <utility> 
using namespace std; 

pair<int,int> a[51];  

int main(){
	int n,x,y; 
	scanf("%d",&n);  
	for (int i = 0; i < n; i++){
		scanf("%d%d",&a[i].first,&a[i].second);  
	}
	for (int i = 0; i < n; i++){
		int cnt = 0; 
		for (int j = 0; j < n; j++){
			if (i == j) continue; 
			if (a[i].first < a[j].first && a[i].second < a[j].second) ++cnt; 
		}
		printf("%d ",cnt+1);  
	}
	printf("\n"); 
	return 0; 
}

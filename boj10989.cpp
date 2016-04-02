#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <algorithm> 
#include <map> 
using namespace std; 

int main(){
	map<int,int> mp; 
	int n,num; 
	scanf("%d",&n); 
	for (int i = 0; i < n; i++){
		scanf("%d",&num); 
		mp[num]++;  
	}
	for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
		for (int i = 0; i < it->second; i++){
			printf("%d\n",it->first);  
		}
	}
	return 0; 
}

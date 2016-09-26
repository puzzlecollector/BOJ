#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <map> 
using namespace std; 

int main(){
	int a,b,c; 
	cin >> a >> b >> c;  
	map<int,int> mp; 
	for (int i = 1; i <= a; i++){
		for (int j = 1; j <= b; j++){
			for (int k = 1; k <= c; k++){
				mp[i+j+k]++; 
			}
		}
	}
	int maxcnt = 0,val;  
	for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
		if (it->second > maxcnt){
			maxcnt = it->second;  
			val = it->first;
		}
	}
	cout << val << endl;
	return 0; 
}

#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map> 
#include <set> 
using namespace std; 
int main(){
	map<int,int> mp; 
	int n; 
	cin >> n; 
	int maxval = -(int)2e9; 
	for (int i = 0; i < n; i++){
		int a,b,c,d; 
		cin >> a >> b >> c >> d; 
		map<int,int> mp; 
		mp[a]++; 
		mp[b]++; 
		mp[c]++;  
		mp[d]++;  
		if (mp.size() == 1){
			maxval = max(maxval,50000 + mp.begin()->first * 5000); 
		}else if (mp.size() == 2){
			if (mp.begin()->second == 2){
				maxval = max(maxval,2000 + 500 * mp.begin()->first + 500 * mp.rbegin()->first); 
			}else{
				for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
					if (it->second == 3){
						maxval = max(maxval,10000 + it->first * 1000); 
						break; 
					}
				}
			}
		}else if (mp.size() == 3){	
			for (map<int,int>::iterator it = mp.begin(); it != mp.end(); it++){
				if (it->second == 2){
					maxval = max(maxval,it->first * 100 + 1000); 
					break;  
				}
			}
		}else if (mp.size() == 4){
			maxval = max(maxval,mp.rbegin()->first * 100); 
		}
	}
	cout << maxval << endl; 
	return 0; 
}

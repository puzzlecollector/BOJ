#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <vector> 
#include <algorithm> 
using namespace std;  

int main(){
	int t; 
	scanf("%d",&t); 
	while (t--){
		vector<int> v; 
		int n; 
		scanf("%d",&n);  
		for (int i = 0; i < n; i++){
			int num; 
			scanf("%d",&num);
			v.push_back(num);   
		}
		sort(v.begin(),v.end());  
		int des = v.size()-1;  
		int ret = 0;  
		int L,R; 
		L = R = v[des--];
		while (des > -1){
			if (des > 0){
				int BiggestA = v[des--]; 
				int BiggestB = v[des--];  
				int gap = (L - BiggestA < R - BiggestB) ? R - BiggestB : L - BiggestA; 
				ret = max(ret,gap);  
				L = BiggestA, R = BiggestB;  
			}else{
				int Biggest = v[des--]; 
				int gap = (L - Biggest < R - Biggest) ? R - Biggest : L - Biggest;  
				ret = max(ret,gap); 
			}
		} 
		printf("%d\n",ret); 
	}
	return 0; 
}

#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
#include <algorithm> 
#include <cstring> 
#include <string> 
#include <vector> 
using namespace std; 

string given,a,b;  
int cache[21][101][2];  
int n; 

int solve(int pos,int pick,bool which){
	if (pos == given.size()) return 1;  
	int &ret = cache[pos][pick][which]; 
	if (ret != -1) return ret;  
	ret = 0;  
	if (!which){
		for (int i = pick; i < n; i++){
			if (a[i] == given[pos]){
				ret += solve(pos+1,i+1,true); 
			}
		}
	}else{
		for (int i = pick; i < n; i++){
			if (b[i] == given[pos]){
				ret += solve(pos+1,i+1,false); 
			}
		}
	}
	return ret;  
}	

int main(){
	cin >> given >> a >> b;  
	n = a.size();  
	memset(cache,-1,sizeof(cache)); 
	int ans = solve(0,0,true)+solve(0,0,false); 
	printf("%d\n",ans);  
	return 0;   
}

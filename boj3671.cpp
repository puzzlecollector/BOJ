#include <iostream>
#include <cstdio> 
#include <cstring> 
#include <cstdlib>
#include <sstream> 
#include <vector> 
#include <map> 
#include <algorithm> 
using namespace std;  
const int MAXN = 10000000;  
int notPrime[MAXN]; 
int visited[MAXN]; 
int ans; // initialised to 0 
void eratos(){
	notPrime[0] = notPrime[1] = 1; 
	for (int i = 2; i*i <= MAXN; i++){
		if (!notPrime[i]){
			for (int j = i*i; j <= MAXN; j += i){
				notPrime[j] = 1; 
			}
		}
	}
}
int toInt(string s){
	int n; 
	istringstream iss (s); 
	iss >> n;  
	return n; 
}
void permute(string s,int l,int r){
	if (l == r){
		int x = toInt(s); 
		if (visited[x]) return; 
		visited[x] = 1; 
		ans += (!notPrime[x]); 
		return; 
	}
	for (int i = l; i <= r; i++){
		swap(s[l],s[i]); 
		permute(s,l+1,r); 
		swap(s[l],s[i]); 
	}
}
void simulate(string s,string cur,int i){
	if (i == s.size()){
		if (cur.size() >= 1){
			permute(cur,0,cur.size()-1); 
		}
		return; 
	}
	simulate(s,cur,i+1); 
	simulate(s,cur+s[i],i+1); 
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL); 
	eratos(); 
	int t; 
	cin >> t;  
	while (t--){
		memset(visited,0,sizeof(visited)); 
		string number; 
		cin >> number; 
		simulate(number,"",0); 
		cout << ans << endl; 
		ans = 0;  
	}
	return 0;  
}

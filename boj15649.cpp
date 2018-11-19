// accepted 
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
#include <set> 
using namespace std; 
void permute(string s,int l,int r,vector<string> &ans){
	if (l == r){
		ans.push_back(s);  
		return; 
	}
	for (int i = l; i <= r; i++){
		swap(s[i],s[l]); 
		permute(s,l+1,r,ans); 
		swap(s[i],s[l]); 
	}
}
int N,M; 
vector<string> v;  
void combination(int k,string s,int past){
	if (k == M){
		v.push_back(s); 
		return; 
	}
	if (past == -1){
		for (int i = 1; i<= N; i++){
			s += string(1,char(i+'0'));  
			combination(k+1,s,i);  
			s.pop_back(); 
		}
	}else{
		for (int i = past+1; i <= N; i++){
			s += string(1,char(i+'0'));  
			combination(k+1,s,i);  
			s.pop_back();
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);  
	cin >> N >> M;  
	string s; 
	// N choose M 
	combination(0,s,-1); 
	vector<string> ans; 
	for (int i = 0; i < v.size(); i++){
		permute(v[i],0,v[i].size()-1,ans); 
	}
	sort(ans.begin(),ans.end()); 
	for (int i = 0; i < ans.size(); i++){
		for (int j = 0; j < ans[i].size(); j++){
			cout << ans[i][j] << " "; 
		}
		cout << "\n"; 
	}
	return 0; 
}

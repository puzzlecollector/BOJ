// timeout - failed code 
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector> 
#include <set> 
using namespace std; 
void permute(string s,int l,int r,set<string> &st){
	if (l == r){
		st.insert(s);  
		return; 
	}
	for (int i = l; i <= r; i++){
		swap(s[i],s[l]); 
		permute(s,l+1,r,st); 
		swap(s[i],s[l]); 
	}
}
int main(){
	int N,M; 
	cin >> N >> M;  
	string s; 
	for (int i = 0; i < N-M; i++){
		s += "0"; 
	}
	for (int i = 0; i < M; i++){
		s += "1"; 
	}
	set<string> st; 
	permute(s,0,s.size()-1,st); 
	vector<string> ans; 
	for (set<string>::iterator it = st.begin(); it != st.end(); it++){
		string t = *it; 
		string L;  
		for (int j = 0; j < t.size(); j++){
			if ((t[j]-'0')&1){
				L += string(1,char(j+1+'0'));  
			}
		}
		set<string> f;  
		permute(L,0,L.size()-1,f); 
		for (set<string>::iterator it = f.begin(); it != f.end(); it++){
			ans.push_back(*it); 
		}
	}
	sort(ans.begin(),ans.end()); 
	for (int i = 0; i < ans.size(); i++){
		for (int j = 0 ;j < ans[i].size(); j++){
			cout << ans[i][j]; 
			if (j == ans[i].size()-1) cout << endl; 
			else cout << " "; 
		}
	}
	return 0; 
}

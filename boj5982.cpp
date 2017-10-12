#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std;
string password,dp[1111],w[1111];  
bool match(int x,int y){
	for (int i = 0; i < w[y].size(); i++){
		if (password[x+i] != '?' && password[x+i] != w[y][i]) return false; 
	}
	return true; 
}  
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); cout.tie(NULL);  
	int L,NW; 
	cin >> L >> NW >> password; 
	for (int i = 0; i< NW; i++){
		cin >> w[i];  
	}
	for (int i = L-1; i >= 0; i--){
		for (int j = 0; j < NW; j++){
			int k = i+w[j].size();  
			if (k <= L && (k == L || !dp[k].empty()) && match(i,j)){
				if (dp[i].empty() || dp[i] > w[j]+dp[k]){
					dp[i] = w[j]+dp[k];  
				}
			}
		}
	}
	cout << dp[0] << endl; 
	return 0; 
}

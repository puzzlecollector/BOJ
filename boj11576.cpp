#include <iostream>
#include <cstdlib>
#include <cstdio> 
#include <cmath> 
#include <vector>
#include <algorithm> 
using namespace std; 

int AtoDec(vector<int> &v, int A){
	reverse(v.begin(),v.end()); 
	int val = 0; 
	for (int i = 0; i < v.size(); i++){
		val += pow(A,i)*v[i];  
	}
	return val; 
}

vector<int> DectoB(int n, int B){
	vector<int> res; 
	while (n){
		res.push_back(n%B);  
		n /= B; 
	}
	reverse(res.begin(),res.end());  
	return res; 
}

int main(){
	int A,B,m,num; 
	vector<int> v;  
	scanf("%d %d",&A,&B); 
	scanf("%d",&m); 
	for (int i = 0; i < m; i++){
		scanf("%d",&num); 
		v.push_back(num);  
	}
	int val = AtoDec(v,A); 
	vector<int> ans = DectoB(val,B); 
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << " "; 
	}
	cout << endl;
	return 0; 
}

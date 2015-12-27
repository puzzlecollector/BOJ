// Problem Link: https://www.acmicpc.net/problem/10773
#include <iostream> 
#include <stack> 
#include <algorithm> 
using namespace std; 

int main(){
	stack<int> st; 
	int k,n,sum=0; 
	cin >> k; 
	for (int i=0; i<k; i++){
		cin >> n; 
		if (n == 0){
			st.pop(); 
		}else{
			st.push(n); 
		}
	}
	while (!st.empty()){
		sum += st.top(); 
		st.pop(); 
	}
	cout << sum << endl; 
	return 0; 
}

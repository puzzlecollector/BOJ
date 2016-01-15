/*
Code that is not accepted. Can't find problems yet. Will fix later 
*/ 

#include <iostream> 
#include <cstdlib> 
#include <cmath> 
#include <algorithm> 
#include <string> 
#include <sstream> 
using namespace std;  

int len(int n){
	int exponent,num=0;  
	for (int i = 0;;i++){
		if (pow(10,i) > n){
			break; 
		}else{
			exponent = i; 
		}
	}
	num += (n-pow(10,exponent)+1)*(exponent+1);   
	for (int i = 0; i < exponent; i++){
		num += 9*pow(10,i);  
	}
	return num;  
}	

string toString(int n){
	stringstream ss; 
	ss << n;  
	return ss.str();  
}

int main(){
	int n,k; 
	cin >> n >> k; 
	if (len(n) < k){
		cout << -1 << endl; 
	}else{
		// k 번째 자리 숫자를 계산하고 출력한다. 
		int sum = 0, cnt = k,idx;  
		for (int i = 0;;i++){
			if (k < sum){
				break; 
			}else{
				idx = i; 
				sum += 9*pow(10,i);           
			}
		}
		for (int i = 0; i < idx; i++){
			cnt -= 9*pow(10,i);  
		}
		int d = idx+1,ans; 
		if (cnt%d == 0){
			ans = (pow(10,idx)+(cnt/d)-1); 
			ans %= 10; 
			cout << ans << endl; 
		}else{
			ans = pow(10,idx)+(cnt/d)-1+(cnt%d);   
			string s = toString(ans); 
			cout << s[cnt%d-1] << endl; 
		}
	}
	return 0;  
}

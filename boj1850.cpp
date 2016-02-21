#include <iostream>
#include <cstdlib>
#include <algorithm> 
using namespace std; 

typedef long long ll; 

ll gcd(ll a, ll b){
	if (a%b == 0) return b; 
	return gcd(b,a%b); 
}

int main(){
	ll A,B; 
	cin >> A >> B; 
	for (int i = 0; i < gcd(A,B); i++){
		cout << '1';  
	}
	cout << endl; 
	return 0;  
}

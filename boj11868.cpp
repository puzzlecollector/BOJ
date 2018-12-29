//  모두 0인 배치는 내가 가져가면서 나타난다 
#include <iostream>
using namespace std; 
typedef long long ll; 
ll p[100]; 
int main(){	
	int n; 
	cin >> n;  
	for (int i = 0; i< n; i++){
		cin >> p[i]; 
	}
	ll x = p[0]; 
	for (int i = 1; i < n; i++){
		x ^= p[i]; 
	}
	if (x == 0){
		cout << "cubelover" << endl; 
	}else{
		cout << "koosaga" << endl; 
	}
}

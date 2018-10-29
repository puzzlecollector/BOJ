#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		int x; 
		cin >> x; 
		for (int j = 0; j < x; j++){
			cout << "="; 
		}
		cout << endl; 
	}
	return 0; 
}

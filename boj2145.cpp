#include <iostream>
#include <cstdlib>
using namespace std; 
int main(){
	while (1){
		int x; 
		cin >> x; 
		if (x == 0) break; 
		while (x >= 10){
			int sum = 0;  
			int d = x; 
			while (d){
				sum += d%10; 
				d /= 10; 
			}
			x = sum; 
		}
		cout << x << endl; 
	}
	return 0; 
}

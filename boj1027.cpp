// referred to http://codersbrunch.blogspot.com/2016/10/1027.html
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std; 
int a[55],b[55];  
int main(){
	int n; 
	cin >> n;  
	for (int i = 0; i < n; i++){
		cin >> a[i];  
	}
	for (int i = 0; i < n; i++){
		double t = -9e9,m; 
		for (int j = i+1; j < n; j++){
			m = (double)(a[j]-a[i])/(j-i);  
			if (m > t){
				t = m;  
				b[i]++; 
				b[j]++;  
			}
		}
	}
	cout << *max_element(b,b+n) << endl; 
	return 0;  
}

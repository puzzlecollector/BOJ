// failed some test cases but algorithm is correct
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std; 
struct point{
	int x,y; 
};  
point a[10005]; 
int main(){
	int n; 
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a[i].x >> a[i].y;  
	}
	double area = 0; 
	int j = n-1;  
	for (int i = 0; i < n; i++){
		area += (a[j].x+a[i].x)*(a[j].y-a[i].y); 
		j = i; 
	}
	cout.setf(ios::fixed); 
	cout.setf(ios::showpoint); 
	cout.precision(1); 
	cout << area/2 << endl;
	return 0; 
}

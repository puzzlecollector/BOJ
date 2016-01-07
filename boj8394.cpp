// Problem Link: https://www.acmicpc.net/problem/8394
#include <iostream> 
#include <cstdlib> 
using namespace std;  

int fib[10000001];  

int main(){
	int n;
	cin >> n; 
	fib[0] = 1; 
	fib[1] = 1;  
	fib[2] = 2; 
	for (int i = 3; i <= n; i++){
		fib[i] = (fib[i-1]%10 + fib[i-2]%10)%10;  
	}
	cout << fib[n] << endl; 
	return 0; 
}

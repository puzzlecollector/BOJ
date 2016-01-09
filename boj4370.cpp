// Problem Link: https://www.acmicpc.net/problem/4370 
// For this problem, we notice that the Baekjoon will win if 
// (2^k)(9^k) < n <= (2^k)(9^k+1) and Donghyuk will win if 
// (2^k)(9^k+1) < n <= (2^k+1)(9^k+1)
#include <iostream>
#include <cstdlib> 
#include <string> 
using namespace std; 

int main(){
	long long n;  
	while (cin >> n){
		int p = 1; 
		while (true){
			p *= 9; 
			if (p >= n){
				cout << "Baekjoon wins." << endl; 
				break; 
			}
			p *= 2; 
			if (p >= n){
				cout << "Donghyuk wins." << endl; 
				break; 
			}

		}
	}
	return 0; 
}

// Problem Link: https://www.acmicpc.net/problem/10448#
// The Eureka Theorem!! 
// Just another complete search problem. 
#include <iostream> 
#include <cstdlib> 
#include <vector> 
#include <cmath> 
using namespace std; 

void findTriangleNo(int num, vector<int>& v){
	for (int i = 1;;i++){
		int val = (i)*(i+1)/2; 
		if (val <= num){
			v.push_back(val); 
		}else break; 
	}
}

int main(){
	int n,num; 
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> num; 
		vector<int> v; 
		findTriangleNo(num,v);  
		bool flag = false; 
		// vector v is filled with triangle numbers less than or equal to num. 
		// now we implement complete search. 
		for (int j = 0; j < v.size(); j++){
			if (flag) break; 
			for (int k = 0; k < v.size(); k++){
				if (flag) break; 
				for (int l = 0; l < v.size(); l++){
					if (num == v[j] + v[k] + v[l]){
						cout << 1 << endl; 
						flag = true; 
						break; 
					}
				}
			}
		}
		if (!flag) cout << 0 << endl; 
	}
	return 0; 
}

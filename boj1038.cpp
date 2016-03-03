#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std; 

vector<string> v; 

void recur(int n, int leftmost, string str){ // n:자릿수의 길이, leftmost:(가장 왼쪽에서)시작하는 숫자, str: 숫자를 만들어가기위한 string 객체 
	if (n == 1){
		v.push_back(str+char(leftmost+48)); 
		return; 
	}
	for (int i = 0; i < leftmost; i++){
		recur(n-1,i,str+char(leftmost+48));
	}
}

int main(){	
	v.push_back("0");  
	for (int digits = 1; digits <= 10; digits++){
		for (int leftmost = 1; leftmost <= 9; leftmost++){
			recur(digits,leftmost,""); 
		}
	}
	// v는 0부터 9876543210까지 채워져있다.  
	int N; 
	cin >> N; 
	if (N >= (int)v.size()){
		cout << -1 << endl; 
	}else{
		cout << v[N] << endl; 
	}
	return 0; 
}

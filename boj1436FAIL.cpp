// Did not get accept yet, although my code seems correct. Will try to fix later when I have time. 
#include <iostream>
#include <string> 
#include <sstream> 
#include <cstdio> 
using namespace std; 

string a[20000]; 

string toString(int n){
	stringstream ss; 
	ss << n; 
	return ss.str(); 
}

int main(){
	a[1] = "666";  
	int i = 2, k = 1;
	// k는 앞에 붙히는 숫자를 나타낸다. i는 배열에 저장될 인덱스를 나타낸다. 
	while (i <= 10000){
		string d = toString(k); 
		if (d[d.size()-1] == '6'){
			for (int j = 0; j <= 9; j++){
				a[i] = d + "66" + char(j+48); 
				++i;
			}
		}else{
			a[i] = d+"666"; 
			++i;  
		}
		++k; 
	}
	int n; 
	cin >> n; 
	cout << a[n] << endl; 
	/*
	for (int i = 1; i <= 10000; i++){
		cout << a[i] << endl; 
	}*/  
	return 0; 
}

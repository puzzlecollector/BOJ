#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <algorithm> 
#include <sstream> 
using namespace std; 

int N; 
int start[4] = {2,3,5,7}; 

bool isPrime(int n){
	for (int i = 2; i*i <= n; i++){
		if (n%i == 0) return false; 
	}
	return n != 1;  
}

int toInt(string s){
	int n;
	istringstream iss (s);  
	iss >> n; 
	return n; 
}

string toString(int n){
	stringstream ss; 
	ss << n; 
	return ss.str(); 
}

void recur(string s,int n){
	if (n == N && isPrime(toInt(s))){
		cout << s << endl;
		return ; 
	}
	for (int i = 1; i <= 9; i++){
		s += char(i+48);  
		if (isPrime(toInt(s))){
			recur(s,n+1);  
		}
		s.pop_back(); 
	}
}

int main(){
	cin >> N; 
	for (int i = 0; i < 4; i++){
		recur(toString(start[i]),1);  
	}
	return 0; 
}

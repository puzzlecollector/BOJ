// Problem Link: https://www.acmicpc.net/problem/11086
#include <iostream>
#include <cstdio> 
#include <sstream>
#include <cstdlib> 
#include <cmath> 
#include <string> 
#include <algorithm> 
using namespace std; 

bool chk(string X, string c1, string Y, string c2, string Z, int base){
	int comp = base; 
	/*
	if (base >= 'a'){
		comp = base-87;  
	}else comp = base; */  
	// first check if we can represent X,Y,Z in the given base 
	int decX = 0, decY = 0, decZ = 0;  
	// check for X 
	for (int i = X.size()-1; i >= 0; i--){
		if (X[i] >= 'a'){
			int val = (X[i]-87);  
			if (val < comp){
				decX += (val)*pow(comp,(int)X.size()-i-1);  
			}else return false;  
		}else{
			if (X[i]-'0' < comp){
				decX += (X[i]-'0')*pow(comp,(int)X.size()-i-1);  
			}else return false;  
		}
	}
	// check for Y
	for (int i = Y.size()-1; i >= 0; i--){
		//cout << Y[i] << endl; 
		if (Y[i] >= 'a'){
			int val = (Y[i]-87); 
			if (val < comp){
				decY += (val)*pow(comp,(int)Y.size()-i-1); 
			}else return false; 
		}else{
			if (Y[i]-'0' < comp){
				decY += (Y[i]-'0')*pow(comp,(int)Y.size()-i-1);  
			}else return false;  
		}
		//cout << decY << endl; 
	}
	// check for Z
	for (int i = Z.size()-1; i >= 0; i--){
		if (Z[i] >= 'a'){
			int val = (Z[i]-87);  
			if (val < comp){
				decZ += (val)*pow(comp,(int)Z.size()-i-1);  
			}else return false; 
		}else{
			if (Z[i]-'0' < comp){
				decZ += (Z[i]-'0')*pow(comp,(int)Z.size()-i-1);  
			}else return false; 
		}
	}
	/*
	cout << "-------------------------------------------" << endl; 
	cout << "base:" << comp << endl; 
	cout << "decX:" << decX << endl; 
	cout << "decY:" << decY << endl; 
	cout << "decZ:" << decZ << endl; 
	cout << "-------------------------------------------" << endl; */ 
	// if we passed all three tests, now check if the 
	// actual equation makes sense 
	if (c1 == "+"){
		return (decX+decY == decZ); 
	}else if (c1 == "-"){
		return (decX-decY == decZ);  
	}else if (c1 == "*"){
		return (decX*decY == decZ);  
	}else if (c1 == "/"){
		return (decX%decY == 0 ? (decX/decY == decZ):false);  
	}
	return false; 
}

bool onlyOnes(string s){
	for (int i = 0; i < s.size(); i++){
		if (s[i] != '1') return false; 
	}
	return true; 
}

int main(){
	string s; 
	string X,Y,Z,c1,c2; 
	int t; 
	cin >> t; 
	//cin.ignore(); 
	for (int i = 0; i < t; i++){
		bool flag = true;  
		cin >> X >> c1 >> Y >> c2 >> Z; 
		// edge case: unary numbers
		if (onlyOnes(X) && onlyOnes(Y) && onlyOnes(Z)){
			int a = X.size(), b = Y.size(), c = Z.size(); 
			if (c1 == "+"){
				if (a+b == c){
					cout << 1; 
					flag = false; 
				}
			}else if (c1 == "-"){
				if (a-b == c){
					cout << 1; 
					flag = false; 
				}
			}else if (c1 == "*"){
				if (a*b == c){
					cout << 1; 
					flag = false; 
				}
			}else if (c1 == "/"){
				if (a%b == 0){
					if (a/b == c){
						cout << 1; 
						flag = false; 
					}
				}
			}
		}
		for (int j = 2; j <= 36; j++){
			if (chk(X,c1,Y,c2,Z,j)){
				if (j <= 9){
					cout << j; 
					flag = false; 
				}else{
					if (j == 36) cout << '0';  
					else{
						cout << char(87+j); 
					}
					flag = false; 
				}
			}
		}
		if (flag){
			cout << "invalid"; 
		}   
		cout << endl; 
	}
	return 0;
}

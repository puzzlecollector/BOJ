/*
Problem Link: https://www.acmicpc.net/problem/10173
*/

#include <iostream> 
#include <cstdlib> 
#include <string> 
#include <sstream> 
using namespace std; 

int main(){
	//cin.ignore(); 
	while (true){
		string s; 
		getline(cin,s);
		if (s == "EOI") break; 
		else{
			istringstream iss (s); 
			string word; 
			bool flag = true; 
			while (iss >> word){
				// change to lower case letter 
				for (int i = 0; i < word.size(); i++){
					if (word[i] >= 'A' && word[i] <= 'Z'){
						word[i] += 32; 
					}
				}
				// search for substring "nemo"
				if (word.find("nemo") != string::npos){
					cout << "Found" << endl; 
					flag = false; 
					break; 
				}
			}
			if (flag) cout << "Missing" << endl; 
		}
	}
	return 0; 
}

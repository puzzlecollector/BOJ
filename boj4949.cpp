#include <iostream>
#include <cstdlib>
#include <stack>
#include <algorithm>
using namespace std;  
int main(int argc,char **argv){
	string s;  
	while (getline(cin,s)){
		if (s == ".") break; 
		stack<char> st;  
		bool cannot = false;  
		for (int i = 0; i < s.size(); i++){
			if (s[i] == '(' || s[i] == '['){
				st.push(s[i]);  
			}else if (s[i] == ')'){
				if (st.empty()){
					cannot = true; 
					cout << "no" << endl; 
					break;  
				}else if (st.top() == '('){
					st.pop();  
				}else{
					cannot = true;  
					cout << "no" << endl; 
					break; 
				}
			}else if (s[i] == ']'){
				if (st.empty()){
					cannot = true; 
					cout << "no" << endl; 
					break; 
				}else if (st.top() == '['){
					st.pop();  
				}else{
					cannot = true;  
					cout << "no" << endl; 
					break; 
				}
			}
		}
		if (!cannot){
			cout << (st.empty() ? "yes" : "no") << endl; 
		}
	}
	return 0; 
}

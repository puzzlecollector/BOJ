#include <iostream>
#include <string> 
#include <algorithm> 
using namespace std;  

int main(){
	string s; 
	getline(cin,s);  
	string t = "";  
	for (int i = 0; i < (int)s.size(); i++){
		if (s[i] == ' ') t += ' ';  
		else if (s[i] >= 'A' && s[i] <= 'Z'){
			int a = (int)s[i]-64;  
			a = (a+13)%26;  
			t += char(a+64);  
		}else if (s[i] >= 'a' && s[i] <= 'z'){
			int a = (int)s[i]-96;  
			a = (a+13)%26; 
			t += char(a+96);  
		}else if (s[i] >= '0' && s[i] <= '9'){
			// ROT13은 알파벳 대문자와 소문자에만 적용할 수 있다. 
			// 알파벳이 아닌 글자는 원래 글자 그대로 남아 있어야 한다. 
			t += s[i];  
		}
	}
	cout << t << endl; 
	return 0; 
}

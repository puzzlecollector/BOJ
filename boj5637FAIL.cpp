#include <iostream> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <sstream> 
#include <algorithm> 
using namespace std; 

int main(){
	string s,t = ""; 
	while (cin >> s){
		if (s == "E-N-D") break; 
		t += s; 
		t += " ";
	}
	istringstream iss (t);  
	string word,longest; 
	int maxlen = 0;  
	while (iss >> word){
		int len = word.size();  
		if (word[0] == '('){
			--len; 
			word = word.substr(1); 
		} 
		if (word[word.size()-1] == ',' || word[word.size()-1] == ')' || word[word.size()-1] == '.'){
			--len; 
			word = word.substr(0,word.size()-1); 
		}
		bool flag = false;  
		for (int i = 0; i < len; i++){
			if (!((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z') || word[i] == '-')){
				flag = true; 
				break; 
			}
		}
		if (flag) continue;  
		if (maxlen < len){
			longest = word; 
			maxlen = len;  
		}
	}
	transform(longest.begin(),longest.end(),longest.begin(),::tolower); 
	cout << longest << endl; 
	return 0; 
}

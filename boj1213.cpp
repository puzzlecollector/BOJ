/*
Problem Link: https://www.acmicpc.net/problem/1213
Given a string, checking if the characters can be rearranged to form a palindrome. 
A string may be a palindrome if at most one character occurs odd number of times.  

This code seems to fail for some test cases - need to be updated!! 
*/
#include <iostream> 
#include <cstdlib> 
#include <string> 
#include <map> 
#include <algorithm> 
using namespace std; 

int main(){
	map<char,int> mp; 
	string s; 
	cin >> s; 
	for (int i = 0; i < s.size(); i++){
		mp[s[i]]++; 
	}
	int cntOdd = 0;  
	char oddChar;  
	for (map<char,int>::iterator it = mp.begin(); it != mp.end(); it++){
		if (it->second%2 == 1){
			++cntOdd;  
			oddChar = it->first;  
		}
	}
	if (cntOdd > 1){
		cout << "I'm Sorry Hansoo" << endl; 
	}else{
		string t = "";  
		if (cntOdd == 1){
			for (map<char,int>::iterator it = mp.begin(); it != mp.end(); it++){
				if (it->first == oddChar) continue; 
				for (int i = 0; i < it->second/2; i++){
					t += it->first;  
				}
 			}
 			string ans = t; 
 			for (int i = 0; i < mp[oddChar]; i++){
 				ans += oddChar; 
 			}
 			reverse(t.begin(),t.end()); 
 			ans += t; 
 			cout << ans << endl; 
		}else{
			for (map<char,int>::iterator it = mp.begin(); it != mp.end(); it++){
				for (int i = 0; i < it->second/2; i++){
					t += it->first;  
				} 
			}
			string ans = t; 
			reverse(t.begin(),t.end()); 
			ans += t; 
			cout << ans << endl;  
		}
	}
	return 0; 
}

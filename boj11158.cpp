/*
Problem Link: https://www.acmicpc.net/problem/11158
using stringstream 
*/ 
#include <iostream> 
#include <string> 
#include <sstream> 
#include <cstdlib> 
using namespace std; 

int main(){
  int n; 
  cin >> n;
  cin.ignore();  
  for (int i = 0; i < n; i++){
    string s; 
    getline(cin,s);  
    stringstream ss; 
    ss << s; 
    int count = 0;  
    string input; 
    string last = ""; 
    while (ss << input){
      if (input == "u") count += 10; 
      else if (input == "ur") count += 10;  
      else if (input.find("lol") != string::npos){
        count += 10; 
      }else if (((last == "would") || (last == "should)) && input == "of"){
        count += 10; 
      }
      last = input;  
    }
    cout << count << endl; 
  }
  return 0; 
}

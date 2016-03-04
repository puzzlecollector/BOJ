#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std; 

int process(int first, int second, vector<int> &v){
	v.push_back(first); v.push_back(second); 
	int cnt = 2; 
	int num = first-second; 
	int temp1 = second; 
	while (num >= 0){
		v.push_back(num);  
		++cnt; 
		int temp2 = temp1-num;  
		temp1 = num; 
		num = temp2;  
	}
	return cnt;  
}

int main(){
	vector<int> ans, temp; 
	int first, maxCnt = 0; 
	cin >> first; 
	for (int i = 1; i <= first; i++){
		int val = process(first,i,temp);  
		if (val > maxCnt){
			maxCnt = val; 
			ans = temp; 
		} 
		temp.clear();  
	}
	cout << maxCnt << endl;
	for (int i = 0; i < ans.size(); i++){
		cout << ans[i] << " "; 
	}
	cout << endl; 
	return 0; 
}

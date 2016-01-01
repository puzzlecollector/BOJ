/*
Problem Link: https://www.acmicpc.net/problem/11637
Quite a sloppy code, but still passes all the test cases
Need to be careful of the case when there are multiple people with maximum votes, because 
in this case, there is no single winner. 
*/
#include <iostream> 
#include <cstdlib> 
#include <vector> 
#include <algorithm> 
using namespace std; 

bool isSame(vector<int>& votes){
	for (int i = 1; i < votes.size(); i++){
		if (votes[0] != votes[i]){
			return false; 
		}
	}
	return true; 
}

bool multipleWinner(vector<int>& votes, int mx){
	int cnt = 0;  
	for (int i = 0; i < votes.size(); i++){
		if (votes[i] == mx){
			++cnt; 
		}
		if (cnt > 1) return true; 
	}
	return false; 
}

int main(){
	int t,n,score;  
	cin >> t; 
	for (int i = 0; i < t; i++){
		vector<int> votes; 
		int sumVotes = 0; 
		int mx = 0,pos;   
		cin >> n; 
		for (int j = 0; j < n; j++){
			cin >> score; 
			if (mx < score){
				mx = score; 
				pos = j+1;  
			}
			sumVotes += score;  
			votes.push_back(score);  
		}
		if (isSame(votes)){
			cout << "no winner" << endl; 
		}else if (multipleWinner(votes,mx)){
			cout << "no winner" << endl; 
		}else{
			if (mx > sumVotes/2){
				cout << "majority winner " << pos << endl; 
			}else{
				cout << "minority winner " << pos << endl; 
			}
		}
	}
	return 0; 
}

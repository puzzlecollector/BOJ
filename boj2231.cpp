/*
Problem Link: https://www.acmicpc.net/problem/2231
Implementation!! hehe 이런문제는 거저먹기 
*/

#include <iostream> 
#include <cstdlib> 
using namespace std; 

int main(){
	int N, ans = -1; 
	cin >> N; 
	for (int i = 1; i <= N; i++){
		int sum = 0;  
		sum += i; 
		int temp = i; 
		while (temp){
			sum += (temp%10); 
			temp /= 10;  
		}
		if (sum == N){
			ans = i; 
			break; 
		}
	}
	if (ans == -1) cout << 0 << endl;
	else cout << ans << endl; 
	return 0; 
}

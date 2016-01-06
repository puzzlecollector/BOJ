/* Problem Link: https://www.acmicpc.net/problem/2303
5개중 3개의 숫자 카드를 골랐을때 그 3개의 숫자들의 합의 일의자리가 가장 큰 사람. 
만약 가장 큰 숫자를 갖는 사람이 두 명 이상일 경우에는 번호가 가장 큰 사람의 번호를 출력한다. 
Brute force solution 
*/
#include <iostream> 
#include <cstdlib> 
#include <vector> 
#include <algorithm> 
using namespace std; 

#define MAX 1001

int n,maxi,cnt,idx; 
int maxPoint[MAX]; // 1,2,...i번째 사람까지의 최대 점수를 저장한다. 
int cards[MAX][5]; // 주어진 카드의 정보를 저장한다.  

int main(){
	// 입력을 받는다. 
	cin >> n; 
	for (int i = 0; i < n; i++){
		for (int j = 0; j < 5; j++){
			cin >> cards[i][j]; 
		}
	}
	// 각 사람의 최대 점수를 계산하고, 게임에 참가한 사람들중 가장 높은 점수를 찾는다.  
	for (int i = 0; i < n; i++){
		vector<int> v; 
		for (int j = 0; j < 5; j++){
			v.push_back(cards[i][j]); 
		}
		for (int j = 0; j < 5; j++){
			for (int k = j+1; k < 5; k++){
				for (int l = k+1; l < 5; l++){
					maxPoint[i] = max(maxPoint[i],(v[j]+v[k]+v[l])%10); 
				}
			}
		}	
		maxi = max(maxi,maxPoint[i]); 
	}
	// 누가 게임을 이겼는지 확정한다.
	for (int i = 0; i < n; i++){
		if (maxPoint[i] == maxi){
			idx = i+1;  
		}
	}
	// 정답을 출력한다. 
	cout << idx << endl; 
	return 0; 	
}

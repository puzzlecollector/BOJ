/*
Note: this solution receives memory limit exceed in the online judge. 
Refer to boj2293-2.cpp that I will upload later for an accepted solution. 
Problem Link: https://www.acmicpc.net/problem/2293#
동전들이 주어지고 어떠한 수 k가 주어졌을때 이 동전들로 k를 만들 수 있는 경우의 수를 
모두 구하는 프로그램을 작성해야한다. 일단 한 동전을 고르거나 고르지 않거나 두 경우중 
하나이므로 점화식은 num = count(n-1,sum)+count(n-1,sum-a[n-1])일 것이다.  
이 함수는 참조적 투명함수이고 (referentially transparent) 따라서 메모이제이션을 적용할 수 있다. 
하지만 아래 코드는 메모리 초과 판정을 받는다. 일차원 배열을 이용해서 문제를 해결하는 솔루션도  
올릴것이다. 

시간복잡도는 부분문제의 갯수 O(nk)이다.  
*/

#include <cstdio> 
#include <iostream>
#include <cstring> 
#include <algorithm>
using namespace std; 

int a[100]; 
int cache[100][10000]; 

int count(int n, int sum){
	int& ret = cache[n][sum]; 
	if (ret != -1) return ret;  
	// 기저: 합이 0일때, 아무 동전도 쓰지 않는다. 
	if (sum == 0){
		return ret = 1; 
	}
	// 기저: 합이 0보다 적을때, 해가 없다. 
	if (sum < 0){
		return ret = 0; 
	}
	// 기저: 합이 1 이상이고 동전의 갯수가 0이하일때, 해가 없다. 
	if (sum >= 1 && n <= 0){
		return ret = 0; 
	}
	return ret = count(n-1,sum)+count(n,sum-a[n-1]); 
}

int main(){
	memset(cache,-1,sizeof(cache)); 
	int n,k; 
	cin >> n >> k; 
	for (int i = 0; i < n; i++){
		cin >> a[i];  
	}
	int ans = count(n,k); 
	cout << ans << endl;
	return 0; 
}

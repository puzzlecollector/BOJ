#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
long long bino[32][32];  
void calcBino(){
	for (int i = 0; i <= 31; i++){
		bino[i][0] = bino[i][i] = 1; 
		for (int j = 1; j < i; j++){
			bino[i][j] = bino[i-1][j-1]+bino[i-1][j];  
		}
	}
}
string generate(int n,int m,long long skip){ // n: number of zeros, m: number of ones 
	if (n == 0) return ""; 
	if (m == 0) return string(n,'0');
	int sum = 0;  
	for (int i = 0; i <= m; i++){
		sum += bino[n-1][i];  
	}  
	if (sum >= skip){
		return "0"+generate(n-1,m,skip);  
	}
	return "1"+generate(n-1,m-1,skip-sum);  
}
int main(){
	int N,L;
	long long I;  
	cin >> N >> L >> I;  
	calcBino(); 
	cout << generate(N,L,I) << endl; 
	return 0;  
}

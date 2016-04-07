// problem that requires simple greedy algorithm. Time complexity O(N^2). 
#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
using namespace std; 

int a[1001];  

int main(){
	int R,N;  
	while (true){
		cin >> R >> N;  
		if (R == -1 && N == -1) break; 
		for (int i = 0; i < N; i++){
			cin >> a[i]; 
		}
		sort(a,a+N);  
		int i = 0, ans = 0;  
		while (i < N){
			int s = a[i++];  
			while (i < N && a[i] <= s+R){
				i++; 
			}
			int p = a[i-1];
			while (i < N && a[i] <= p+R){
				i++;  
			}  
			ans++; 
		}
		cout << ans << endl; 
	}
	return 0; 
}

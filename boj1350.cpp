#include <iostream> 
#include <cstdlib> 
#include <cmath>
#include <vector> 
using namespace std; 

int main(){
	int n,fs,cs; 
	cin >> n;  
	vector<int> v;  
	for (int i = 0; i < n; i++){
		cin >> fs;  
		v.push_back(fs);  
	}
	cin >> cs; 
	long long ans = 0; 
	for (int i = 0; i < n; i++){
		int temp = v[i];  
		int cnt = ceil((double)temp/cs); 
		ans += cs*cnt;  
	}
	cout << ans << endl; 
	return 0;  
}

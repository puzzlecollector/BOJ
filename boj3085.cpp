// brute force search. 
// But a naive search will create TLE. We need some serious pruning. 
#include <iostream> 
#include <cstdlib>
#include <algorithm> 
#include <vector> 
using namespace std; 

int N; 
char grid[51][51]; 

bool inRange(int y, int x){
	return (y >= 0 && y < N && x >= 0 && x < N);
}

int longestConsecutiveChar(string s){
	int cnt = 0, temp = 1; 
	for (int i = 0; i < s.size()-1; i++){
		if (s[i] == s[i+1]) ++temp;  
		else{
			cnt = max(cnt,temp);  
			temp = 1;  
		}
	}	
	cnt = max(cnt,temp); 
	return cnt;  
}

int main(){
	// get input. 
	cin >> N; 
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			cin >> grid[i][j]; 
		}
	}
	int maxCnt = 0;  
	// swap 
	// this is an O(N^3) algorithm. 
	for (int i = 0; i < N; i++){
		for (int j = 0; j < N; j++){
			// swap characters horizontally
			// we only need to check row i, cols j,j+1 for updates
			if (inRange(i,j+1)){
				swap(grid[i][j],grid[i][j+1]);  
				string a,b,c; 
				for (int k = 0; k < N; k++){ // row i
					a += grid[i][k];  
				}
				for (int k = 0; k < N; k++){ // col j
					b += grid[k][j];  
				}
				for (int k = 0; k < N; k++){ // col j+1
					c += grid[k][j+1]; 
				}
				int v1 = longestConsecutiveChar(a), v2 = longestConsecutiveChar(b), v3 = longestConsecutiveChar(c); 
				maxCnt = max(maxCnt,max(v1,max(v2,v3)));   
				swap(grid[i][j],grid[i][j+1]);  
			}
			// swap characters vertically 
			// we only need to check rows i,i+1 and col j for updates  
			if (inRange(i+1,j)){
				swap(grid[i][j],grid[i+1][j]); 
				string a,b,c; 
				for (int k = 0; k < N; k++){ // row i 
					a += grid[i][k];  
				}
				for (int k = 0; k < N; k++){ // row i+1
					b += grid[i+1][k]; 
				}
				for (int k = 0; k < N; k++){ // col j
					c += grid[k][j];  
				}
				int v1 = longestConsecutiveChar(a), v2 = longestConsecutiveChar(b), v3 = longestConsecutiveChar(c);  
				maxCnt = max(maxCnt,max(v1,max(v2,v3))); 
				swap(grid[i][j],grid[i+1][j]);  
			}
		}
	}
	cout << maxCnt << endl; 
	return 0; 
}

#include <iostream> 
#include <cstdlib> 
#include <algorithm> 
#include <cstdio> 
#include <stack> 
using namespace std;  

int main(){
	int n,num; 
	scanf("%d",&n); 
	int turn = 1;  
	stack<int> st; 
	for (int i = 1; i <= n; i++){
		scanf("%d",&num);  
		if (num == turn){
			turn++;  
			continue;  
		}
		while (!st.empty() && st.top() == turn){
			st.pop(); 
			turn++; 
		}
		st.push(num); 
	}
	while (!st.empty()){
		if (st.top() != turn){
			printf("Sad\n"); 
			return 0; 
		}else{
			st.pop(); 
			turn++;  
		}
	}
	printf("Nice\n"); 
	return 0; 
}

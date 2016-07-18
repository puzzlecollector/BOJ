 // 절댓값이 가장 작은 수를 출력한다. 만약 값이 여러개라면 더 작은 수를 출력  
#include <iostream> 
#include <queue> 
#include <cstdlib> 
#include <cstdio> 
#include <algorithm>
using namespace std;  

typedef pair<int,int> P; // abs value,actual value

int main(){
	int n; 
	scanf("%d",&n);  
	priority_queue< P,vector<P>,greater<P> > que;  
	while (n--){
		int num; 
		scanf("%d",&num); 
		if (num == 0){
			if (que.empty()) printf("0\n"); 
			else printf("%d\n",que.top().second),que.pop();  
		}else{
			que.push(P(abs(num),num));  
		} 
	}
	return 0; 
}

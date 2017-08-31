#include <iostream>
#include <cstdlib>
#include <cstring> 
#include <algorithm>
#include <vector> 
using namespace std; 
const int MAXN = 101;  
struct brickInfo{
	int area,height,weight,idx;  
}; 
bool cmp(brickInfo b1,brickInfo b2){
	return (b1.area < b2.area);  
}
brickInfo bricks[MAXN];  
struct resInfo{
	int above,curIdx,height;
}; 
resInfo dp[MAXN];  
int main(){
	int n; 
	scanf("%d",&n);  
	for (int i = 0; i < n; i++){
		// base area, height, width 
		scanf("%d %d %d",&bricks[i].area,&bricks[i].height,&bricks[i].weight);  
		bricks[i].idx = i+1; // index number
	}
	sort(bricks,bricks+n,cmp);  
	dp[0].above = 0;  
	dp[0].curIdx = bricks[0].idx; 
	dp[0].height = bricks[0].height; 
	// start looking from the box with the second smallest base area  
	for (int i = 1; i < n; i++){
		for (int j = 0; j < i; j++){
			if (bricks[i].weight > bricks[j].weight){
				// we can put j above i
				if (dp[i].height < dp[j].height+bricks[i].height){
					dp[i].height = dp[j].height+bricks[i].height; 
					dp[i].above = j; 
					dp[i].curIdx = bricks[j].idx;   
				}
			}
		}
		if (dp[i].height == 0){
			dp[i].above = i; 
			dp[i].curIdx = bricks[i].idx; 
			dp[i].height = bricks[i].height;  
		}
	}
	int maxHeight = 0, maxIdx = 0; 
	for (int i = 0; i < n; i++){
		if (dp[i].height > maxHeight){
			maxHeight = dp[i].height; 
			maxIdx = i;  
		}
	}
	vector<int> v; 
	v.push_back(bricks[maxIdx].idx); 
	while (true){
		if (dp[maxIdx].above == maxIdx) break; 
		maxIdx = dp[maxIdx].above; 
		v.push_back(bricks[maxIdx].idx);  
	}
	printf("%d\n",(int)v.size()); 
	reverse(v.begin(),v.end()); 
	for (int i = 0; i < v.size(); i++){
		printf("%d\n",v[i]); 
	}
	return 0;  
}

#include <iostream>
#include <cstdio> 
#include <cstdlib>
#include <cmath> 
#include <algorithm> 
using namespace std;  
bool chk(int x,int y,int W,int H,int X,int Y){
	// within rectangle 
	if (x >= X && x <= X+W && y >= Y && y <= Y+H) return true; 
	// within left circle   
	double r = H/2.0;  
	double lx = X, ly = Y+r;  
	double d = sqrt((lx-x)*(lx-x) + (ly-y)*(ly-y));  
	if (d <= r) return true;  
	// within right circle 
	double rx = X+W, ry = Y+r;  
	d = sqrt((rx-x)*(rx-x) + (ry-y)*(ry-y));  
	if (d <= r) return true; 
	return false;  
}
int main(int argc,char **argv){
	int W,H,X,Y,P,x,y,cnt = 0;  
	scanf("%d %d %d %d %d",&W,&H,&X,&Y,&P); 
	while (P--){
		scanf("%d %d",&x,&y);  
		if (chk(x,y,W,H,X,Y)) cnt++; 
	}
	printf("%d\n",cnt); 
	return 0;  
}

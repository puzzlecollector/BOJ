#include <iostream> 
#include <cstdlib> 
#include <cstdio> 
#include <algorithm> 
using namespace std;  

int main(){
	int w,h,p,q,t;  
	scanf("%d %d %d %d %d",&w,&h,&p,&q,&t);  
	int cnt1 = (p+t)/w, cnt2 = (q+t)/h;  
	if (cnt1%2 == 0) printf("%d ",(p+t)%w);  
	else printf("%d ",w-(p+t)%w);  
	if (cnt2%2 == 0) printf("%d\n",(q+t)%h);  
	else printf("%d\n",h-(q+t)%h);  
	return 0; 
}

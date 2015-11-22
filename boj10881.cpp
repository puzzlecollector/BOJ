/*
Problem Link: https://www.acmicpc.net/problem/10881
제 블로그에다가 문제 해설을 포스트 해놨어요!: http://blog.naver.com/programmer18/220467836992
*/

#include <iostream> 
#include <cstdio> 
#include <algorithm> 
#include <cstdlib> 
#include <climits> 
using namespace std; 
 
int main(){
    int t,a1,b1,a2,b2,a3,b3; 
    scanf("%d",&t);
    for (int i = 0; i < t; i++){
        scanf("%d%d%d%d%d%d",&a1,&b1,&a2,&b2,&a3,&b3); 
        // 선물 상자를 일렬로 놓는 방법: 
        int minval1 = INT_MAX; 
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                for (int k = 0; k < 2; k++){
                    minval1 = min(minval1,(a1+a2+a3)*max(b1,max(b2,b3))); 
                    swap(a3,b3);  
                }
                swap(a2,b2); 
            }
            swap(a1,b1); 
        }
        // 선물 상자를 T자로 놓는 방법 
        // formation 1 
        int minval2 = INT_MAX;  
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                for (int k = 0; k < 2; k++){ 
                    minval2 = min(minval2,(max(a1,a2)+a3)*max(b1+b2,b3)); 
                    swap(a3,b3);  
                }
                swap(a2,b2); 
            }
            swap(a1,b1); 
        }    
        // formation 2 
        swap(a1,a3);  
        swap(b1,b3); 
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                for (int k = 0; k < 2;k++){
                    minval2 = min(minval2,(max(a1,a2)+a3)*max(b1+b2,b3)); 
                    swap(a3,b3);  
                }
                swap(a2,b2); 
            }
            swap(a1,b1); 
        }
        // formation 3
        swap(a2,a3); 
        swap(b2,b3);  
        for (int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                for (int k = 0; k < 2;k++){
                    minval2 = min(minval2,(max(a1,a2)+a3)*max(b1+b2,b3)); 
                    swap(a3,b3);  
                }
                swap(a2,b2); 
            }
            swap(a1,b1); 
        }
        // 일렬과 T자로 놓는 방법들을 비교해서 최솟값 찾고 출력하기 
        int res = min(minval1,minval2); 
        printf("%d\n",res);  
    }
    return 0; 
}

#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio> 
using namespace std; 

int A,B,N; // we are given that N is at most 500. 
int cost,numCity,travelCost = 5000; 
int routes[505][505];  
int costInfo[505], sizeInfo[505];  
int twoRoutes[1015]; 

int main(){	
	cin >> A >> B >> N;  
	// find the minimum travel cost when using only one route 
	for (int i = 0; i < N; i++){
		bool flag1 = false, flag2 = false; 
		cin >> cost >> numCity; 
		costInfo[i] = cost;  
		sizeInfo[i] = numCity; 
		for (int j = 0; j < numCity; j++){
			cin >> routes[i][j];  
			if (routes[i][j] == A) flag1 = true; 
			if (routes[i][j] == B && flag1) flag2 = true; 
		}
		if (flag1 && flag2) travelCost = min(travelCost,cost);  
	}	
	// find the minimum travel cost when using two routes.   
	// given route "first" and route "second", there are two ways of attaching them 
	// (first + second) and (second + first). 
	for (int i = 0; i < N; i++){
		for (int j = i+1; j < N; j++){
			int sizeFirst = sizeInfo[i]; 
			int sizeSecond = sizeInfo[j];  
			// first + second 
			for (int k = 0; k < sizeFirst; k++){
				twoRoutes[k] = routes[i][k];  
			}
			for (int k = 0; k < sizeSecond; k++){
				twoRoutes[sizeFirst+k] = routes[j][k];  
			}
			bool flag1 = false, flag2 = false;  
			for (int k = 0; k < sizeFirst + sizeSecond; k++){ 
				if (twoRoutes[k] == A) flag1 = true; 
				if (twoRoutes[k] == B && flag1){
					flag2 = true; break; 
				}
			}
			if (flag1 && flag2){
				travelCost = min(travelCost,costInfo[i]+costInfo[j]);  
			}
			// second + first   
			for (int k = 0; k < sizeSecond; k++){
				twoRoutes[k] = routes[j][k]; 
			}
			for (int k = 0; k < sizeFirst; k++){
				twoRoutes[sizeSecond+k] = routes[i][k];  
			}
			flag1 = flag2 = false; 
			for (int k = 0; k < sizeFirst + sizeSecond; k++){
				if (twoRoutes[k] == A) flag1 = true; 
				if (twoRoutes[k] == B && flag1){
					flag2 = true; break; 
				}
			}
			if (flag1 && flag2){
				travelCost = min(travelCost,costInfo[i]+costInfo[j]);  
			}
		}
	}
	cout << (travelCost == 5000 ? -1 : travelCost) << endl; 
	return 0; 
}

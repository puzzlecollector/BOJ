#include <iostream>
#include <algorithm>
#include <vector>
#include <queue> 
using namespace std; 

int N;  
priority_queue<int, vector<int>, greater<int> > timeEvents;  
priority_queue<int, vector<int>, greater<int> > distanceEvents;  

double curD, curT; 
int speed; 

int main(){
	cin >> N;  
	for (int i = 0; i < N; i++){
		char c; int x; 
		cin >> c >> x; 
		if (c == 'T'){
			timeEvents.push(x); 
		}else{
			distanceEvents.push(x); 
		}
	}
	distanceEvents.push(1000);  
	curT = curD = 0.0;  
	speed = 1; 
	while (!timeEvents.empty() || !distanceEvents.empty()){
		bool isNextT = false; 
		if (distanceEvents.empty()){
			isNextT = true; 
		}else if (!distanceEvents.empty() && !timeEvents.empty()){
			if (timeEvents.top() < (curT + (distanceEvents.top()-curD)*speed)){
				isNextT = true; 
			}
		}
		if (isNextT){
			curD += (timeEvents.top() - curT)/(speed+0.0);  
			curT = timeEvents.top();  
			timeEvents.pop();  
		}else{
			curT += (distanceEvents.top()-curD)*speed; 
			curD = distanceEvents.top(); 
			distanceEvents.pop(); 
		}
		++speed;  
	}
	int currentTime = (int)curT;  
	double frac = curT-currentTime; 
	if (frac < 0.5) cout << currentTime << endl; 
	else cout << currentTime+1 << endl; 
	return 0; 
}

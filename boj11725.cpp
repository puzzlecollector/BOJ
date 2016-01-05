// Problem Link: https://www.acmicpc.net/problem/11725
// BFS: finding the parent node of a given node in a tree. 
#include <iostream>
#include <cstdlib> 
#include <vector> 
#include <algorithm> 
#include <queue> 
using namespace std; 

int parent[100005]; 

int main(){
	int n,a,b;  
	cin >> n;
	vector< vector<int> > tree;   
	tree.resize(n+1);
	for (int i = 0; i < n-1; i++){
		cin >> a >> b; 
		tree[a].push_back(b); 
		tree[b].push_back(a);  
	}	
	queue<int> q;  
	q.push(1); 
	while (!q.empty()){
		int f = q.front(); 
		q.pop(); 
		for (int i = 0; i < tree[f].size(); i++){
			if (!parent[tree[f][i]]){
				parent[tree[f][i]] = f; 
				q.push(tree[f][i]); 
			}
		}
	}
	for (int i = 2; i <= n; i++){
		cout << parent[i] << endl; 
	}
	return 0;  
}

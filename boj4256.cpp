/// given preorder and inorder, print postorder of the binary tree 
#include <iostream>
#include <cstdlib>
#include <algorithm> 
#include <cstring> 
#include <vector>
#include <queue>
#include <stack> 
using namespace std; 
vector<int> slice(const vector<int> &v,int a,int b){
	return vector<int>(v.begin()+a,v.begin()+b);  
}
void printPostOrder(const vector<int> &preorder,const vector<int> &inorder){
	const int N = preorder.size();  
	if (preorder.empty()) return;  
	const int root = preorder[0]; 
	// L is the size of the left subtree 
	const int L = find(inorder.begin(),inorder.end(),root)-inorder.begin(); 
	// print left subtree  
	printPostOrder(slice(preorder,1,L+1),slice(inorder,0,L));  
	// print right subtree  
	printPostOrder(slice(preorder,L+1,N),slice(inorder,L+1,N)); 
	printf("%d ",root);   
}
int main(){
	int t; 
	scanf("%d",&t); 
	while (t--){
		int n; 
		scanf("%d",&n); 
		vector<int> preorder(n), inorder(n);  
		for (int i = 0; i < n; i++){
			scanf("%d",&preorder[i]); 
		}
		for (int i = 0; i < n; i++){
			scanf("%d",&inorder[i]);  
		}
		printPostOrder(preorder,inorder); 
		printf("\n"); 
	}
	return 0;  
}

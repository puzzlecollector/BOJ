/*
tree traversal program. 
performs preorder traversal, inorder traversal and 
postorder traversal.   

preorder: (루트)(왼쪽 자식)(오른쪽 자식) 
inorder: (왼쪽 자식)(루트)(오른쪽 자식) 
postorder: (왼쪽 자식)(오른쪽 자식)(루트)
*/
#include <iostream>
#include <cstdio> 
#include <cstdlib> 
#include <algorithm> 
using namespace std; 

char a[27][3];  
int n; 

struct node{
	char data; 
	struct node *left; 
	struct node *right;  
}; 

struct node *newNode(char data){
	struct node *node = (struct node *)malloc(sizeof(struct node));  
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	return (node);  
}

void printPreOrder(struct node *root){
	if (root == NULL){
		return; 
	}
	cout << root->data;    
	printPreOrder(root->left); 
	printPreOrder(root->right);  
}

void printInorder(struct node *root){
	if (root == NULL){
		return; 
	}
	printInorder(root->left);  
	cout << root->data; 
	printInorder(root->right);  
}

void printPostOrder(struct node *root){
	if (root == NULL){
		return; 
	}
	printPostOrder(root->left); 
	printPostOrder(root->right); 
	cout << root->data;    
}

void insert(struct node *root, char c){
	if (root == NULL){
		return; 
	}
	for (int i = 0; i < n; i++){
		if (a[i][0] == c){
			if (a[i][1] != '.') root->left = newNode(a[i][1]);  
			insert(root->left,a[i][1]);  
			if (a[i][2] != '.') root->right = newNode(a[i][2]);  
			insert(root->right,a[i][2]); 
		}
	}
}

int main(){
	cin >> n;   
	struct node *root = newNode('A');  
	for (int i = 0; i < n; i++){
		cin >> a[i][0] >> a[i][1] >> a[i][2];  
	}
	insert(root,'A');  
	printPreOrder(root); cout << endl; 
	printInorder(root); cout << endl; 
	printPostOrder(root); cout << endl; 
	return 0; 
}

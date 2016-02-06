// solve using circular linked list. 
// Problem Link: https://www.acmicpc.net/problem/11866
#include <iostream>
#include <cstdio> 
#include <algorithm> 
#include <cstdlib> 
#include <cstring> 
using namespace std;  

int n,m; 

typedef struct CLL{
	int data; 
	int visited; 
	struct CLL *next;  
}CLL; 

void InsertAtEndInCLL(CLL **head, int data){
	CLL *current = *head;  
	CLL *newNode = (struct CLL*)malloc(sizeof(struct CLL));  
	if (!newNode){
		return;  
	}
	newNode->data = data; 
	newNode->visited = 0; 
	newNode->next = newNode; // 우선 새로운 노드가 자기 자신을 가리키게 한다. 
	if (*head == NULL){
		*head = newNode;  
	}else{
		while (current->next != *head){
			current = current->next; 
		}
		newNode->next = *head; 
		current->next = newNode; 
	}
}

void Josephus(CLL *head){
	CLL *temp = head; 
	int cnt = 0; 
	printf("<");  
	while (cnt < n){
		int move = 0;  
		if (cnt == n-1){
			while (move < m-1){
				temp = temp->next; 
				if (!(temp->visited)) ++move;  
			}
			printf("%d>\n",temp->data);  
		}else{
			while (move < m-1){
				temp = temp->next;  
				if (!(temp->visited)) ++move; 
			}
			printf("%d, ",temp->data); 
			temp->visited = 1;  
			temp = temp->next; 
			while (temp->visited){
				temp = temp->next; 
			}
		}
		++cnt; 
	}
}

int main(){
	scanf("%d%d",&n,&m); 
	CLL *head = NULL; 
	for (int i = 1; i <= n; i++){
		InsertAtEndInCLL(&head,i); 
	}
	Josephus(head);  
	return 0;
}

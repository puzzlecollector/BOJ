// alternate template code that may solve the Josephus Problem. 

#include <stdio.h> 
#include <stdlib.h> 

struct ListNode{
	int data; 
	struct ListNode *next;  
}; 

int N,M; 

struct ListNode *GetJosephusPosition(){
	struct ListNode *p,*q;  
	printf("Enter N number of players:"); 
	scanf("%d",&N);  
	printf("Enter Mth person to be eliminated:"); 
	scanf("%d",&M); 
	p = q = malloc(sizeof(struct ListNode));  
	p->data = 1;  
	for (int i = 2; i <= N; i++){
		p->next = malloc(sizeof(struct ListNode)); 
		p = p->next;  
		p->data = i; 
	}
	p->next = q; // connect the ciruclar linked list. 
	for (int count = N; i > 1; i--){
		for (int i = 0; i < M-1; i++){
			p = p->next;  
		}
		p->next = p->next->next; 
	}
	printf("Last player left standing:%d\n",p->data); 
}

int main(){
	// some code 
	return 0; 
}

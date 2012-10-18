/**************************************************************************
InsertNth() which insert a new node at any index within a list.
***************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
struct node{
	int data;
	struct node* next;
};
/*--------Build One Two Three ---------*/ 
struct node* buildonetwothree(){
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;

	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));
	third = malloc(sizeof(struct node));

	head -> data = 1;
	head -> next = second;

	second -> data = 2;
	second -> next = third;

	third -> data = 3;
	third -> next = NULL;

	return head;
}
/*-------------Delete List---------------*/
void deletelist(struct node** headRef){

	struct node* current = *headRef;
	struct node* next;

	for(current = *headRef; current != NULL; current = next){
		next = current->next;
		free(current);
	}
	*headRef = NULL;
}

/*---------------- Push() ---------------------*/
void Push(struct node** headRef, int data){
	struct node* newnode = malloc(sizeof(struct node));

	newnode->data = data;
	newnode->next = *headRef;
	*headRef = newnode;
}
/*-------------------Insert Nth--------------------*/
void InsertNth(struct node** headRef, int index, int data){
	if (index == 0)
   	Push(headRef, data);   // position 0 is a special case.
else {
  	struct node* current = *headRef;
	   int i;
     	for (i=0; i<index-1; i++) {
 	    assert(current != NULL); // if this fails, index was too big
  	   current = current->next;
      }
	Push(&(current->next), data);
	}	
}
/*---------Test Driver---------*/
void main(){
	struct node* head = NULL;
    int index = 0, data = 0;
	insertnth(&head, 0, 13);
	insertnth(&head, 1, 42);
	insertnth(&head, 1, 5);
    printf("index:%d\ndata:%d", index, data);
	deletelist(&head);
}

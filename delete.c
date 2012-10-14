/**************************************************************************
write a function DeleteList() that takes a list, deallocates all of its memory and sets its head pointer to NULL(the empty list)
***************************************************************************/
#include<stdio.h>
#include<stdlib.h>
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
/*----------------Test Driver---------------------*/
void main(){
	struct node* mylist = buildonetwothree();
	deletelist(&mylist);

}

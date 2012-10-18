/********************************************************************************
RecursiveReverse(): Recursively reverses the given linked list by changing its
.next pointers and its head pointer in one pass of the list.
********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};

void RecursiveReverse(struct node** headRef);
void PrintList(struct node* head);
struct node* BuildOneTwoThree();
/*------Recursive Reverse------*/
void RecursiveReverse(struct node** headRef) {

	struct node* next = (*headRef)->next;
	struct node* previous = (*headRef);
	(*headRef) = next;

	if((*headRef) != NULL){
	RecursiveReverse(headRef);
	}

	if((*headRef) == NULL)
  	(*headRef) = previous;
	else
	{
	next->next = previous;
	previous->next = NULL;
	}
}
/*----------BuildOneTwoThree()--------------*/
struct node* BuildOneTwoThree(){
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;

	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));
	third = malloc(sizeof(struct node));

	head->data = 1;
	head->next= second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	return head;
}
/*-------PrintList-------*/
void PrintList(struct node* head)
{
	struct node* temp = head;
	int i = 0;
	if(head == NULL)
	  printf("Linked List Is Empty..\n\n");
	else
	  printf("Printing Linked List..\n\n");
	while(temp != NULL){
	  printf("%d\n", temp->data);
	  temp = temp->next;
        }	
}
/*-------Test Driver----------*/
main(){
	  struct node* head = BuildOneTwoThree();
	  PrintList(head);
	  RecursiveReverse(&head);
 	  PrintList(head);
}


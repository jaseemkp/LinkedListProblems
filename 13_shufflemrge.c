/***************************************************************************
Given two lists, merge their nodes together to make one list, taking nodes 
alternately between the two lists.
***************************************************************************/
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};
struct node* ShuffleMerge(struct node* a, struct node* b);
void MoveNode(struct node** destRef, struct node** sourceRef);
struct node* BuildOneTwoThree();
struct node* BuildOneTwo();
void PrintList(struct node* head);
/*-----------ShuffleMerge-------------*/ 
struct node* ShuffleMerge(struct node* a, struct node* b){
	struct node* merged = NULL;
	while((a != NULL) || (b != NULL))
	{
	   if(b != NULL)
	     MoveNode(&merged, &b);
	   if(a != NULL)
	     MoveNode(&merged, &a);
	}
	return merged;
}
/*-------------MoveNode---------------*/
void MoveNode(struct node** destRef, struct node** sourceRef){
	if((*sourceRef) != NULL)
	{
	   struct node* dest = (*destRef);
	   (*destRef) = (*sourceRef);
	   struct node* source = (*sourceRef)->next;
	   (*sourceRef) = source;
	   (*destRef) -> next = dest;
	}
}
/*---------PrintList()-----------*/
void PrintList(struct node* head)
{
	struct node* temp = head;
	int i = 0;
	if(head == NULL)
	   printf("Linked List is Empty..\n\n");
	else
	   printf("Printing the linked List...\n\n");
	while(temp != NULL){
	   printf("%d\n", temp->data);
	   temp = temp->next;
	}
}
/*----------BuildOneTwoThree()------------*/
struct node* BuildOneTwoThree(){
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
/*----------BuildOneTwo()--------------*/
struct node* BuildOneTwo(){
	struct node* head = NULL;
	struct node* second = NULL;
	
	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));
	
	head -> data = 1;
	head -> next = second;

	second -> data = 2;
	second -> next = NULL;

	return head;
}
/*-----------TEST DRIVER--------------*/
 main(){
	struct node* a = BuildOneTwo();
	printf("List A:\n");
	PrintList(a);
	struct node* b = BuildOneTwoThree();
	printf("List B:\n");
	PrintList(b);
	struct node* merged = ShuffleMerge(a,b);
	struct node* temp = merged;
	printf("Meged List:\n");
	PrintList(temp);
   
}

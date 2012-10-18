/***************************************************************************
Write a SortedMerge() function that takes two lists, each of which is sorted
in incrasing order, and merge the two together into one list which is in 
increasing order.
***************************************************************************/
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* SortedMerge(struct node *a, struct node* b);
void MoveNode(struct node** destRef, struct node** sourceRef);
struct node* BuildOneTwo();
struct node* BuildOneTwoThree();
void PrintList(struct node* head);
/*----------Sorted Merge------------*/
struct node* SortedMerge(struct node* a, struct node *b){
	struct node* merged = NULL;
	while(( a != NULL) || (b != NULL))
	{
	 if((a != NULL) && (b != NULL))
	  {
	    if(a->data < b->data)
	     MoveNode(&merged, &a);
	    else if(a->data > b->data)
	     MoveNode(&merged, &b);
	    else
	      {
		MoveNode(&merged, &b);
		a = a->next;
	      }
	   }
	   else if(a != NULL)
	       MoveNode(&merged, &a);
	    else if(b != NULL)
	       MoveNode(&merged, &b);
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
	
	head -> data = 4;
	head -> next = second;

	second -> data = 5;
	second -> next = NULL;

	return head;
}
/*-------------Test Driver-----------*/
main(){
	struct node* a = BuildOneTwo();
	struct node* b = BuildOneTwoThree();
	struct node* merged = SortedMerge(a,b);
	struct node* temp = merged;
	PrintList(temp);
}

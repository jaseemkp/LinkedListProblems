/**************************************************************************
This is a variant on Push(). Instead of creating a new node and pushing it 
onto the given list, MoveNode() takes two lists, removes the front node from
 the second list and pushes it onto the front of the first
***************************************************************************/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};
void MoveNode(struct node** destRef, struct node** sourceRef);
struct node* BuildOneTwoThree();
void PrintList(struct node* head);
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
/*------------PrintList----------*/
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
/*-----------------MoveNode--------------*/
void MoveNode(struct node** destRef, struct node** sourceRef){
	if((*sourceRef) != NULL){
   	   struct node* dest = (*destRef);
 	   (*destRef) = (*sourceRef);
  	   struct node* source = (*sourceRef)->next;
   	   (*sourceRef) = source;
       	   (*destRef)->next = dest;
	}
}
/*-----------------Test Driver------------*/
int main(){
	struct node* a = BuildOneTwoThree();
	struct node* b = BuildOneTwoThree();
	PrintList(a);
	PrintList(b);
	MoveNode(&a, &b);
	printf("Printing New Destination:\n\n");
	PrintList(a);
	printf("Printing New Source:\n\n");
	PrintList(b);
  return 0;
}


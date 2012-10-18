/**************************************************************************
Write a function AlternatingSplit() that takes one list and divides up its 
nodes to make two smaller lists. The sublists should be made from alternati
ng elements in the original list is {a,b,a,b,a}, then one sublist should be
{a,a,a}
***************************************************************************/
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

void AlternatingSplit(struct node* source, struct node** aRef, struct node** bRef);
int Length(struct node* head);
void MoveNode(struct node** destRef, struct node** sourceRef);
void PrintList(struct node* head);
struct node* BuildOneTwoThree();
/*----------Alternating Aplit----------*/ 
void AlternatingSplit(struct node* source, struct node** aRef, struct node** bRef){
	struct node* tempA = source;
	int length = Length(source);
	int iterations = 0;
	while(iterations != (length))
	{
	   iterations++;
	   if(iterations%2)
	      MoveNode(bRef, &source);
	   else
	      MoveNode(aRef, &source);
	}
}
/*----------Length----------*/
int Length(struct node* head){
	struct node* current = head;
	int count = 0;
	
 	while(current != NULL){
	   count++;
	   current = current->next;
	}
	return count;
}
/*------------MoveNode----------*/
void MoveNode(struct node** destRef, struct node** sourceRef){
	if((*sourceRef) != NULL){
	  struct node* dest = (*destRef);
	  (*destRef) = (*sourceRef);
	  struct node* source = (*sourceRef)->next;
	  (*sourceRef) = source;
	  (*destRef)->next = dest;
	}
}
/*----------PrintList----------*/
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
/*-----------BuildOneTwoThree--------*/
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
/*--------Test Driver--------*/
int main()
{
	  struct node* source = BuildOneTwoThree();
 
 	  struct node* aRef = NULL;
  	  struct node* bRef = NULL;
 	  AlternatingSplit(source,&aRef,&bRef);
	  printf("Sorted list is : \n \n");
  	  PrintList(bRef);
 	  PrintList(aRef);
   return 0;
}

/***************************************************************************
Given a list, split it into two sublist- one for the front half, and one the
back half.if the number of elements is odd, the extra element should go in 
the front list.
***************************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* BuildOneTwoThree();
void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef);
void PrintList(struct node* head);
int Length(struct node* head);
/*-----------BuildOneTwoThree----------*/
struct node* BuildOneTwoThree(){
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;
//	struct node* fourth = NULL;
//	struct node* fifth = NULL;

	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));
	third = malloc(sizeof(struct node));
//	fourth = malloc(sizeof(struct node));
//	fifth = malloc(sizeof(struct node));

	head->data = 1;
	head->next = second;
	second->data = 3;
	second->next = third;
	third->data = 4;
	third->next = NULL;
//	fourth->data = 7;
//	fourth->next = fifth;
//	fifth->data = 8;
//	fifth->next = NULL;
   return head;
}

/*------------FrontBackSplit-------------*/
void FrontBackSplit(struct node* source, struct node** frontRef, struct node** backRef){

	(*frontRef) = source;
	struct node* front = (*frontRef);
	int length = Length(source);
	int index = 0, iterations;
	if(length == 1)
	{
	  iterations = length-1;
	}
	else{
	    if(length%2 == 0)
	      iterations = length/2 -1;
	    else
	      iterations = length/2;
	}
	while(front != NULL){
	   if(iterations == index)
	   {
	    (*backRef) = front->next;
	    front->next = NULL;
	    break;
	   }
	index++;
	front = front->next;
}
}

/*---------PrintList----------*/
void PrintList(struct node* head){
	struct node* temp = head;
	int i = 0;
	if(head == NULL)	
	   printf("Linked List is Empty..\n\n");
	else
	   printf("Printing the linked list..\n\n");
	while(temp != NULL){
	   printf("%d\n", temp->data);
	   temp = temp->next;
	}
}
/*-----------Length-------------*/
int Length(struct node* head){
	struct node* current = head;
	int count = 0;

	while(current != NULL){
	   count++;
	   current = current->next;
	}
	return count;
}
/*----------Test Driver------------*/
int main(){
	struct node* head = BuildOneTwoThree();
	struct node* fronthead = NULL;
	struct node* backhead = NULL;
	PrintList(head);
	FrontBackSplit(head, &fronthead, &backhead);
	struct node* headf = fronthead;
	printf("_______Head List________\n");
	PrintList(headf);
	struct node* headb = backhead;
	printf("_______Back List________\n");
	PrintList(headb);
    return 0; 
}

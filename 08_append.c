/***************************************************************************
Write an Append() function that takes two lists. 'a' and 'b', appends 'b' on
to the end of 'a' and then set 'b' to NULL
***************************************************************************/
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};
struct node* BuildOneTwoThree();
struct node* BuildFourFive();
void Append(struct node** aRef, struct node** bRef);
/*----------BuildOneTwoThree-----------*/
struct node* BuildOneTwoThree(){
	struct node* head = NULL;
	struct node* second = NULL;
	struct node* third = NULL;

	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));
	third = malloc(sizeof(struct node));

	head->data = 1;
	head->next = second;
	
	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;
   return head;
}
/*----------BuildFourFive------------*/
struct node* BuildFourFive(){
	struct node* head = NULL;
	struct node* second = NULL;
	
	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));

	head->data = 4;
	head->next = second;
	second->data = 5;
	second->next = NULL;
   return head;
}

/*------------Append----------------*/
void Append(struct node** aRef, struct node** bRef){

	struct node* tempA = *aRef;
	struct node* temp = *aRef;
	while((tempA)!= NULL)
	{
	   printf("aref in loop: %d\n", (tempA->data));
	   temp = tempA;
	   (tempA) = (tempA)->next;
	}
	temp->next = (*bRef);
	(*bRef) = NULL;
}
/*--------------Test Driver------------*/
int main(){
	struct node* List1 = BuildOneTwoThree();
	struct node* head = List1;
	struct node* List2 = BuildFourFive();
	struct node* head1 = List2;
	
	Append(&head, &head1);

	struct node* head2 = List1;
	while(head != NULL)
	{
	   printf("%d\n", head->data);
	   head = head->next;
	}
   return 0;
}

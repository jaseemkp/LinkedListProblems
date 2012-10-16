/**************************************************************************
Write a SortedInsert() function which given a list that is sorted in 
increasing order, and a single node, insert the node into the correct sorted
 position in the list.While Push() allocates a new node to add to the list, 
SortedInsert() takes the existing node, and just rearranges pointers to 
insert it into the list.
***************************************************************************/
#include<stdio.h>
#include<stdlib.h>

struct node {
int data;
struct node* next;
};

struct node* BuildOneTwoThree();
void SortedInsert(struct node** headRef, struct node* newNode);
/*------------------TEST DRIVER--------------------*/
int main(){
	struct node* head = BuildOneTwoThree();
	struct node* newNode = (struct node*)malloc(sizeof(struct node));
	newNode->data = 2;
	newNode->next = NULL;
	SortedInsert(&head, newNode);
	struct node* current = head;
	while(current != NULL)
		{
		  printf("%d\n",current->data);
		  current = current->next;
	}
    return 0;
}
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
/*-------------------SortedInsert()----------------------*/
void SortedInsert(struct node** headRef, struct node* newNode){
	struct node* temp = NULL;
	struct node* current = *headRef;
	
	if(current != NULL)
	{
	while(current != NULL)
	  { 
  	    if(current->data > newNode->data)
	      break;
	   temp = current;
	   current = current->next;
	}
	newNode->next = current;
	if(temp != NULL)
	  {
	    temp->next = newNode;
	  }
	  else{
  	    (*headRef) = newNode;
	    }
	}
	else{
	(*headRef) = newNode;
        }
}


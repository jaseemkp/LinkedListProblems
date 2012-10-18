/**************************************************************************
Write InsertSort() function which given a list, rearrange its nodes so they
are sorted in increasing order. It should use SoretedInsert()
***************************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* BuildOneTwoThree();
void PrintList(struct node* head);
void SortedInsert(struct node** headRef, struct node* newNode);

/*----------BuildOneTwoThree()--------------*/
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
/*-----------InsertSort()-------------*/
void InsertSort(struct node** headRef){
	struct node* sortedList = NULL;
	struct node *head = *headRef;
	while(head != NULL)
	{
	   struct node* insert = (struct node*)malloc(sizeof(struct node));
	   insert->data = head->data;
	   insert->next = NULL;
	   SortedInsert(&sortedList,insert);
	   head = head->next;
	}
	(*headRef) = sortedList;
}

/*--------------SortedInsert()----------------*/
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

/*-----------PrintList()--------------*/
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
/*---------------TEST DRIVER----------------*/
int main(){
 	struct node* head = BuildOneTwoThree();
	PrintList(head);
	InsertSort(&head);
	PrintList(head);
    return 0;
}

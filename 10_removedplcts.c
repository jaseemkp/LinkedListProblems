/***************************************************************************
Write a RemoveDuplicates() function which takes a list sorted in increasing
 order and delete any duplicate nodes from the list.Ideally, the list should
only be travesed once.
***************************************************************************/
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

struct node* BuildOneTwo();
void RemoveDuplicates(struct node* head);
void PrintList(struct node* head);
/*-------------BuildOneTwo------------*/
struct node* BuildOneTwo(){
	struct node* head = NULL;
	struct node* second = NULL;
	
	head = malloc(sizeof(struct node));
	second = malloc(sizeof(struct node));

	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = NULL;
    return head;
}
/*----------RemoveDuplicates----------*/
void RemoveDuplicates(struct node* head){
	struct node* temp = head;
	while(temp != NULL)
	{
	 struct node* temp1 = temp->next;
	 if(temp1 != NULL)
	{
	  if(temp ->data == temp1->data)
	   {
	    struct node* duplicate = temp->next;
	    while(temp->data == duplicate->data)
		{
		  duplicate = duplicate->next;
	        }
		temp->next = duplicate;
	   }
	}
	temp = temp->next;
}
}
/*----------Print List-----------*/
void PrintList(struct node* head)
{
	struct node* temp = head;
	int i = 0;
	if(head == NULL)
	   printf("Linked List Is Empty..\n\n");
	else
	   printf("Printing The Linked List..\n\n");
	while(temp != NULL)
	{
	   printf("%d\n", temp->data);
	   temp = temp->next;
	}
}
/*--------Test Driver---------*/
int main(){
	struct node* head = BuildOneTwo();
	printf("Original linked list with duplicates:\n\n");
	PrintList(head);
	RemoveDuplicates(head);
	printf("Linked list without duplicate\n\n");
	PrintList(head);
}

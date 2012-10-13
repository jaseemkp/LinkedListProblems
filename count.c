/************************************************************************** write Count() function that counts the number of times a given int occurs
 in a list. The code for this has the classic list traversal structure as 
demonstarated in Lenght()
***************************************************************************/
#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};

struct node* buildonetwothree(){
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

void main(){
	struct node*  myList = buildonetwothree(); // {1, 2, 3}

	int count = Count(myList, 2);
	printf("%d\n", count);
}
int Count(struct node* head, int search){
	struct node* current = head;
	int count = 0;
	
	for(current = head; current != NULL; current = current->next){
		if(current->data == search)
		count++;
		}
	return count;
}



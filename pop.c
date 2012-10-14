/*************************************************************************
pop() needs to unlink the front node from the list and deallocate it with a call to free() .
**************************************************************************/
int pop(struct** headRef){
	struct node* head;
	int result;

	head = *headRef;
	assert(head != NULL);

	result = head -> data;
	*headRef = head -> next;

	free(head);
	return(result);
}

#include "inverted_search.h"

int insert_at_last(Slist **head, char *data)
{
    // creating a new node.
    Slist *new = malloc(sizeof(Slist));
    // validating DMA.
    if (new == NULL)
	return FAILURE;
    else
    {
	// updating the new node data.
	new -> data = malloc(strlen(data));
	// storing the file name in each node.
	strcpy(new -> data, data);
	new -> link = NULL;
	// checking if list is empty or not.
	if (*head == NULL)
	{
	    // linking head and new node.
	    *head = new;
	    return SUCCESS;
	}
	else
	{
	    // intializing the pointer to traverse the list.
	    Slist *temp = *head;
	    // traverse to the last node.
	    while (temp -> link != NULL)
	        temp = temp -> link;
	    // linking new node and last node.
	    temp -> link = new;	    
	}
	return SUCCESS;
    }
}

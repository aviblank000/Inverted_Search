#include "inverted_search.h"

// Used to check if the filename is stored in the single linked list.
void print_list(Slist *head)
{
    if (head == NULL)
	printf("INFO : List is empty\n");
    else
    {
	while (head)		
	{
	    printf("%s -> ", head -> data);
	    head = head -> link;
	}
	printf("NULL\n");
    }
}

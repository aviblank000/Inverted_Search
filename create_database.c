#include "inverted_search.h"

// function defintion to conver lower case char to upper case.
int to_upper(char ch)
{
    if (ch >= 97 && ch <= 122)
	return ch - 32;
}

int create_database(Slist *head, Mlist **hashtable)
{
    // temp pointer is used to traverse the single linked list where filenames are store.
    Slist *temp = head;
    while (temp)
    {	
	FILE *fp = fopen(temp -> data, "r");
	char s[100];
	int flag = 1, f1;
	while (1)
	{
	    // if fp reaches end of file.
	    if (fscanf(fp, "%s", s) == EOF)
		break;
	    
	    flag = 1;
	    // hash function to get the index.
	    int index = to_upper(s[0]) % 65;

	    // if there is no main node in the index of the hashtable.
	    if (hashtable[index] == NULL)
	    {
		// creating main node and sub node.
		Mlist *mnew = create_main_node(s);
		Sublist *snew = create_sub_node(temp -> data);
		// linking sub node to main node.
		mnew -> slink = snew;
		// linking main node to the hashtable.
		hashtable[index] = mnew;
	    }
	    else
	    {
		// if there is a node at the index of the hash table.

		// using t1 to traverse the main nodes in the hash table.
		Mlist *t1 = hashtable[index];		
		
		// running a loop to check if the word is present in the hash table index.
		f1 = 0;
		while (t1 != NULL)
		{
		    if (strcmp(t1 -> word, s) == 0)
		    {
			f1 = 1;
			break;
		    }
		    t1 = t1 -> mlink;
		}
		// resetting t1 to starting index if word is not found.
		if (t1 == NULL)
		    t1 = hashtable[index];

		// if there is a word in the main node.
		if (f1)
		{
		    // pr to hold previous sub node address, t2 to traverse the sub nodes.
		    Sublist *pr, *t2 = t1 -> slink;
		    // 
		    while(t2 != NULL)
		    {
			// if the filenames are same then increment file count.
			if (strcmp(t2 -> name, temp -> data) == 0)
			{
			    (t2 -> word_count)++;
			    flag = 0;
			    break;
			}
			pr = t2;
			t2 = t2 -> slink;
		    }
		    // if the filename is not present.
		    if (flag)
		    {
			// creating new sub node.
			Sublist *snew = create_sub_node(temp -> data);
			// linking the new sub node to previous node.
			pr -> slink = snew;
			// updating the file count.
			(t1 -> file_count )++;
		    }
		}
		else
		{
		    // if the words are not same.
		    // creating main node and sub node.
		    Mlist *mnew = create_main_node(s);
		    Sublist *snew = create_sub_node(temp -> data);
		    // linking sub node with main node.
		    mnew -> slink = snew;
		    // inserting this main node to the index of the hashtable but at the last.
		    // insert at last operation.
		    Mlist *pre = t1;
		    while (t1 != NULL)
		    {
			pre = t1;
			t1 = t1 -> mlink; 
		    }
		    pre -> mlink = mnew;
		}
	    }
	}
	// traversing the single linked list.
	temp = temp -> link;
    }

    return SUCCESS;
}

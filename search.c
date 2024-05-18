#include "inverted_search.h"

void search(char *s, Mlist **hashtable)
{
    int index;
    // finding the index of the word.
    if (s[0] >= 97 && s[0] <= 122)
	index = (s[0] - 32) % 65;
    else
	index = s[0] % 65;

    // if the index is NULL, word not found.
    if (hashtable[index] == NULL)
    {
	printf("Word not found\n");
	return;
    }
    // if index is not NULL.
    if (hashtable[index])
    {
	// traversing the hashtable index using temp.
	Mlist *temp = hashtable[index];
	while (temp != NULL)
	{
	    // checking for the word in the main nodes.
	    if (strcmp(temp -> word, s) == 0)
	    {
		// if word is found, printing word and file count.
		printf("The word '%s' is present in %d file\n", s, temp -> file_count);
		// traversing the subnodes to display the filenames and word count.
		Sublist *t2 = temp -> slink;
		while(t2 != NULL)
		{
		    printf("In File : %s - %d times\n", t2 -> name, t2 -> word_count);
		    t2 = t2 -> slink;
		}
		putchar('\n');
		return;
	    }
	    temp = temp -> mlink;
	}
	// if the word is not found in the index.
	if (temp == NULL)
	    printf("Word not found\n");
	
	return;
    }
}

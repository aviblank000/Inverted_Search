#include "inverted_search.h"

void display(Mlist **hashtable)
{
    // displaying the titles.
    printf("%s %8s %13s\t  %s\n", "[Index]", "[word]", "[file count]", "[filename : word count]");
    for (int i = 0; i < 26; i++)
    {
	// checking if index contains main node.
	if (hashtable[i] != NULL)
	{
	    // temp to travere the main node.
	    Mlist *temp = hashtable[i];
	    // traversing the hashtable index.
	    while (temp != NULL)
	    {
		// printing index,
		printf("[%d]", i);
		// printing the word and file count.
		printf("%13s %13d", temp -> word, temp -> file_count);
		// t2 to traverse the sub nodes.
		Sublist *t2 = temp -> slink;
		// traversing the sub node.
		while(t2 != NULL)
		{
		    // printing the filename and word count.
		    printf("    %s : %d ", t2 -> name, t2 -> word_count);
		    t2 = t2 -> slink;
		} 
		putchar('\n');
		temp = temp -> mlink;
	    }
	}
    }
}

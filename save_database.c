#include "inverted_search.h"

int save_database(char *s, Mlist **hashtable)
{
    // opening the file in write mode.
    FILE *fp = fopen(s, "w");
    for (int i = 0; i < 26; i++)
    {
	// checking if node is present in hashtable.
	if (hashtable[i] != NULL)
	{
	    // traversing the hashtable index using temp.
	    Mlist *temp = hashtable[i];
	    while (temp != NULL)
	    {
		// printing the index, word and filecount into the file.
		fprintf(fp,"#%d;%s;%d;", i, temp -> word, temp -> file_count);
		// traversing the sub nodes using t2.
		Sublist *t2 = temp -> slink;
		while(t2 != NULL)
		{
		    // printing the name and word count into the file.
		    fprintf(fp,"%s;%d;", t2 -> name, t2 -> word_count);
		    t2 = t2 -> slink;
		}
		fprintf(fp,"#\n");
		temp = temp -> mlink;
	    }
	}
    }
    return SUCCESS;
}

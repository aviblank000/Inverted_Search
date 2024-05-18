#include "inverted_search.h"

int update_database(char *s, Mlist ** hashtable)
{
    // opening the file in read mode.
    FILE *fp = fopen(s, "r");
    char ch;
    // Doing file validation.
    if (fp == NULL || (ch = fgetc(fp)) != '#')    
	return FAILURE;	
    // resetting the file pointer.
    rewind(fp);
    while(1)
    {
	char str[100], *token, word[100];
	int index, flag = 1;
	// when file pointer reaches the EOF.
	if (fscanf(fp, "%s", str) == EOF)
	    break;
	// getting the index from the string, converting into integer usint atoi and storing in index var.
	index = atoi(strtok(str + 1, ";"));
	// getting the word from the string and storing in word var.
	strcpy(word, strtok(NULL, ";"));

	Mlist *t1;
	// if hashtable index is NULL.
	if (hashtable[index] == NULL)
	    flag = 1;
	else
	{
	    // if hashtable index is not NULL.
	    t1 = hashtable[index];
	    while(t1 -> mlink != NULL)
		t1 = t1 -> mlink;
	    flag = 0;
	}

	// creating new node and updating file count.
	Mlist *mnew = create_main_node(word);
	mnew -> file_count = atoi(strtok(NULL, ";"));

	// getting tokens of the sub strings.
	while (token != NULL)
	{
	    // pulling the filename.
	    token = strtok(NULL, ";");
	    // checking if end of the string.
	    if (strcmp(token, "#") == 0)
		break;
	    // creating new sub node and updating word count.
	    Sublist *snew = create_sub_node(token);
	    snew -> word_count = atoi(strtok(NULL, ";"));

	    // if there is no sub link.
	    if (mnew -> slink == NULL)
		mnew -> slink = snew;
	    // if there is sub link.
	    else if (mnew -> slink)
	    {
		// traversing to the last of the sub nodes.
		Sublist *temp = mnew -> slink;
		while(temp -> slink != NULL)
		    temp = temp -> slink;
		// inserting the new subnode at the last.
		temp -> slink = snew;		
	    }
	}
	// if there is no main nodes in the index else insert at last at the hashtable index.
	if (flag)
	    hashtable[index] = mnew;
        else
            t1 -> mlink = mnew;	    
    }
    return SUCCESS;
}

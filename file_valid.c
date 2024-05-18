#include "inverted_search.h"


int file_validation(int c, char **argv, Slist **fhead)
{
    // file pointer.
    FILE *fp;
    for (int i = 1; i < c; i++)
    {
	// opening the file.
	fp = fopen(argv[i], "r");
	// file validation.
	if (fp == NULL)	   
	    return FAILURE;
	else
	{
	    char ch;
	    // checking if file is empty.
	    if ((ch = fgetc(fp)) == EOF)
	    {
		printf("File %s is empty\n", argv[i]);
		continue;
	    }
	    // if file is not empty, inserting the filename into single linked list.
	    if (insert_at_last(fhead, argv[i]) == FAILURE) 
	    {
		printf("INFO : Insertion Failure\n");
		return FAILURE;
	    }
	    else
		printf("File %s successfully inserted\n", argv[i]);
	}
    }
    return SUCCESS;
}

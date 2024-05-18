#include "inverted_search.h"

int main(int argc, char *argv[])
{
    Slist *fhead = NULL;
    // Command line Validation.
    if (argc == 1)
	printf("Invalid number of arguments\n");

    if (argc > 1)
    {
	// File validation.
	if (file_validation(argc, argv, &fhead) == SUCCESS)
	    printf("File is validation completed\n\n");
	else
	{
	    printf("File validation failed\n");
	    return -1;
	}
	// Creating a hashtable.
	Mlist *hashtable[26] = {0};
	int flag = 1;
	// Running a loop to display the index.
	while(1)
	{
	    // Displaying the menu options.
	    printf("Select your choice among following options: \n");
	    printf("1. Create DATABASE\n2. Display DATABASE\n3. Update DATABASE\n4. Search\n5. Save DATABASE\n6. Exit\n");
	    // ch to store the option, word to store used input.
	    char ch, word[100], filename[100];
	    // reading option from user.
	    scanf(" %c", &ch);
	    
	    switch(ch)
	    {
		case '1' :
		    if (flag)
		    {
			// calling the function create database.
			if (create_database(fhead, hashtable) == SUCCESS)
			{
			    printf("DATABASE creation successfull\n");
			    //printf("%p\n", hashtable[7]);
			}
			else
			{
			    printf("FAILURE\n");
			    return -1;
			}
			flag = 0;
		    }
		    else
			printf("Update database already selected\n");
		    break;
		case '2':
		    // function to display database.
		    display(hashtable);
		    break;
		case '3':
		    if (flag)
		    {
			// reading filename from user.
			printf("Enter a file name: ");
			scanf("%s", filename);
			// function call for updating database.
			if (update_database(filename, hashtable) == SUCCESS)
			    printf("Save Database successfull\n");
			else
			{
			    printf("Invalid file\n");
			    return -1;
			}
			flag = 0;
		    }
		    else
			printf("Create database already selected\n");
		    break;
		case '4':
		    // reading word for searching.
		    printf("Enter the word you want to search: ");
		    scanf("%s", word);
		    // function call for search.
		    search(word, hashtable);
		    break;
		case '5':
		    // reading filename to save database.
		    printf("Enter a file name: ");
		    scanf("%s", filename);
		    // function call for save database.
		    if (save_database(filename, hashtable) == SUCCESS)
			printf("Save Database successfull\n");
		    else
		    {
			printf("FAILURE\n");
			return -1;
		    }
		    break;
		case '6':
		    exit(0);
	    }
	    printf("\n");
	}
    }
    return 0;
}

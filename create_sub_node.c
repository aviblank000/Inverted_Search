#include "inverted_search.h"

Sublist *create_sub_node(char *s)
{
    // allocating memory for sub node.
    Sublist *snew = malloc(sizeof(Sublist));
    // allocating memory to store filename.
    snew -> name = malloc(strlen(s));
    // copying the filename.
    strcpy(snew -> name, s);
    // initializing the word count.
    snew -> word_count = 1;
    // initialzing the sub link.
    snew -> slink = NULL;
    return snew;
}

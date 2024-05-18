#include "inverted_search.h"

Mlist *create_main_node(char *s)
{
    // allocation memory for main node.
    Mlist *mnew = malloc(sizeof(Mlist));
    // allocating memory to store the word.
    mnew -> word = malloc(strlen(s));
    // copying the word to the main node.
    strcpy(mnew -> word, s);
    // initializing file count.
    mnew -> file_count = 1;
    // initializing sub link and main link.
    mnew -> slink = NULL;
    mnew -> mlink = NULL;
    return mnew;
}


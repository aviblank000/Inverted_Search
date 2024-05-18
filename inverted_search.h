#ifndef IN_S
#define IN_S

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define FAILURE -1

// Structure for single linked list.
typedef struct node
{
        char *data;
        struct node *link;
}Slist;

// Structure for main node.
typedef struct main_node
{
    char *word;
    int file_count;
    struct sub_node *slink;
    struct main_node *mlink;
}Mlist;

// Structure for sub node.
typedef struct sub_node
{
    char *name;
    int word_count;
    struct sub_node *slink;
}Sublist;

// function declaration for file validation.
int file_validation(int c, char **argv, Slist **fhead);

// function declaration for insert at last operation on single linked list.
int insert_at_last(Slist **head, char *data);

// function declaration to print the single linked list.
void print_list(Slist *head);

// function declaration to create database.
int create_database(Slist *head, Mlist **hashtable);

// function declaration to display the database.
void display(Mlist **hashtable);

// function declaration to search the database.
void search (char *s, Mlist **hashtable);

// function declaration to save the database.
int save_database(char *s, Mlist **hashtable);

// function declaration to update the database.
int update_database(char *s, Mlist **hashtable);

// function declaration to create main node.
Mlist *create_main_node(char *s);

// function declaration to create sub node.
Sublist *create_sub_node(char *s);
#endif 

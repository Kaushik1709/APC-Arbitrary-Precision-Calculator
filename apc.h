#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Include the prototypes here */
int create_list(char*str,Dlist **head,Dlist **tail);
int is_number(char *str);
void print_list(Dlist *head);

int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

int subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR,int *is_negative);
int compare(Dlist *h1,Dlist *h2);
int borrow(Dlist *tail1,Dlist *tail2,Dlist **headR,Dlist **tailR);

int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);
int append_zero(Dlist **head, Dlist **tail);
void free_list(Dlist *head);

int division(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR);
void clone_list(Dlist *src, Dlist **dest_head, Dlist **dest_tail);
void trim_leading_zeros(Dlist **head, Dlist **tail);


#endif
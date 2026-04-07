#include "apc.h"

int subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR,int *is_negative)
{
   int cmp = compare(*head1,*head2);
   
   if(cmp == 0)
   {
    /*result = 0*/
    Dlist *new = malloc(sizeof(Dlist));
    if (new == NULL)
    {
        return FAILURE;
    }
    new->data=0;
    new->prev = new->next = NULL;
    *headR = *tailR = new;
    *is_negative = 0;
    return SUCCESS;
   }
   if (cmp > 0)
   {
    *is_negative = 0;
    return borrow(*tail1,*tail2,headR,tailR);
   }
   else
   {
    *is_negative = 1;
    return borrow(*tail2,*tail1,headR,tailR);
   }
}

int compare(Dlist *h1,Dlist *h2)
{
    int len1=0;
    int len2=0;
    Dlist *t;
    for( t = h1; t ; t = t->next)
    {
        len1++;
    }
    for( t = h2; t ; t = t->next)
    {
        len2++;
    }

    if(len1 > len2)
    return 1;
    if(len1 < len2)
    return -1;

    while(h1 && h2)
    {
        if(h1->data > h2->data)
        return 1;
        if(h1->data < h2->data)
        return -1;
        h1=h1->next;
        h2=h2->next;
    }
    return 0;
}

int borrow(Dlist *tail1,Dlist *tail2,Dlist **headR,Dlist **tailR)
{
    int borrow=0;
    while(tail1 != NULL)
    {
        int d1 = tail1->data - borrow;
        int d2 = (tail2 != NULL) ? tail2->data : 0;

        if(d1 < d2)
        {
            d1=d1 + 10;
            borrow = 1;
        }
        else
        {
            borrow =0;
        }

        int digit = d1-d2;
        /* insert at head*/
        Dlist *new = malloc(sizeof(Dlist));
        if(new == NULL)
        return FAILURE;

        new->data = digit;
        new->prev = NULL;
        new->next = *headR;

        if(*headR)
        (*headR)->prev = new;
        else
        *tailR = new;

        *headR = new;

        tail1 = tail1->prev;
        if(tail2)
        tail2= tail2->prev;
    }
    return SUCCESS;
}
#include "apc.h"

int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR)
{
    Dlist *t2 =*tail2;
    int shift =0;

    *headR=NULL;
    *tailR=NULL;

    if(*head1 == NULL || *head2 == NULL)
    return FAILURE;

    while(t2 != NULL)
    {
        int carry =0;
        Dlist *t1 = *tail1;

        Dlist *temp_head =NULL;
        Dlist *temp_tail =NULL;

        /* multiply list1 with single digit t2 */
        while(t1 != NULL)
        {
            int product =(t1->data * t2->data)+carry;
            int digit = product % 10;
            carry = product / 10;

            /* insert at head of temp list */
            Dlist *new = malloc(sizeof(Dlist));
            if(!new)
            return FAILURE;

            new->data = digit;
            new->prev = NULL;
            new->next = temp_head;

            if(temp_head)
                temp_head->prev = new;
            else
                temp_tail = new;

            temp_head = new;
            t1 = t1->prev;
        }
        if(carry)
        {
            Dlist *new= malloc(sizeof(Dlist));
            if(!new)
            return FAILURE;

            new->data = carry;
            new->prev = NULL;
            new->next = temp_head;
            temp_head->prev = new;
            temp_head = new;
        }

        /*  append zeros */
        for(int i=0; i < shift; i++)
        {
            if(append_zero(&temp_head,&temp_tail) == FAILURE)
            return FAILURE;
        }

        /* add temp result to final result */
        if(*headR == NULL)
        {
            *headR = temp_head;
            *tailR = temp_tail;
        }
        else
        {
            Dlist *sum_head=NULL;
            Dlist *sum_tail=NULL;

            if(addition(headR , tailR, &temp_head, &temp_tail, &sum_head, &sum_tail) == FAILURE)
            return FAILURE;

            free_list(*headR);
            free_list(temp_head);

            *headR = sum_head;
            *tailR = sum_tail;
        }
        shift++;
        t2 = t2->prev;
    }
    return SUCCESS;
}

int append_zero(Dlist **head, Dlist **tail)
{
    Dlist *new= malloc(sizeof(Dlist));
    if(!new)
    return FAILURE;

    new->data = 0;
    new->next = NULL;
    new->prev = *tail;

    if(*tail)
        (*tail)->next = new;
    else
        *head = new;

    *tail = new;
    return SUCCESS;
}

void free_list(Dlist *head)
{
    Dlist *temp;
    while(head)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
#include "apc.h"
 

int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR)
{
    
    Dlist *t1 = *tail1;
    Dlist *t2 = *tail2;
    int sum = 0;
    int carry = 0; 
    int digit;

    while (t1 != NULL || t2 != NULL)
    {
        int d1=(t1 != NULL)?t1->data :0;
        int d2=(t2 != NULL)?t2->data :0;

        sum = d1+d2+carry;
        /* for carry */
        if(sum > 9)
        {
            digit = sum - 10;
            carry = 1;
        }
        else
        {
            digit = sum;
            carry = 0;
        }
        

        /* insert at head */
        Dlist *new=malloc(sizeof(Dlist));
        if(new == NULL)
        {
            return FAILURE;
        }
        new->data=digit;
        new->prev=NULL;
        new->next=*headR;

        if(*headR != NULL)
        {
            (*headR)->prev=new;
        }
        else
        {
            *tailR=new;
        }
        *headR = new;
        if(t1)
        t1=t1->prev;
        if(t2)
        t2=t2->prev;
    }
    /* Final Carry */
    
        if (carry)
        {
            Dlist*new=malloc(sizeof(Dlist));
            if(new == NULL)
            return FAILURE;

            new->data=carry;
            new->prev=NULL;
            new->next=*headR;
            (*headR)->prev = new;
            *headR = new;
        }
    return SUCCESS;
}
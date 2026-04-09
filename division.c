#include "apc.h"

int division(Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2,Dlist **headR, Dlist **tailR)
{
    /* division by zero check */
    if (*head2 == NULL)
        return FAILURE;

    /* if dividend < divisor → result = 0 */
    if (compare(*head1, *head2) < 0)
    {
        Dlist *zero = malloc(sizeof(Dlist));
        zero->data = 0;
        zero->prev = zero->next = NULL;
        *headR = *tailR = zero;
        return SUCCESS;
    }

    Dlist *remainder_head = NULL, *remainder_tail = NULL;
    clone_list(*head1, &remainder_head, &remainder_tail);

    *headR = *tailR = NULL;

    while (compare(remainder_head, *head2) >= 0)
    {
        int count = 0;

        /* subtract divisor repeatedly */
        while (compare(remainder_head, *head2) >= 0)
        {
            Dlist *temp_head = NULL, *temp_tail = NULL;
            borrow(remainder_tail, *tail2, &temp_head, &temp_tail);

            free_list(remainder_head);
            remainder_head = temp_head;
            remainder_tail = temp_tail;

            trim_leading_zeros(&remainder_head, &remainder_tail);
            count++;
        }

        /* insert quotient digit at tail */
        Dlist *new = malloc(sizeof(Dlist));
        new->data = count;
        new->next = NULL;
        new->prev = *tailR;

        if (*tailR)
            (*tailR)->next = new;
        else
            *headR = new;

        *tailR = new;
    }

    free_list(remainder_head);
    return SUCCESS;
}

void clone_list(Dlist *src, Dlist **dest_head, Dlist **dest_tail)
{
    while (src)
    {
        Dlist *new = malloc(sizeof(Dlist));
        new->data = src->data;
        new->prev = *dest_tail;
        new->next = NULL;

        if (*dest_tail)
            (*dest_tail)->next = new;
        else
            *dest_head = new;

        *dest_tail = new;
        src = src->next;
    }
}

void trim_leading_zeros(Dlist **head, Dlist **tail)
{
    while (*head && (*head)->data == 0)
    {
        Dlist *tmp = *head;
        *head = (*head)->next;
        if (*head)
            (*head)->prev = NULL;
        free(tmp);
    }

    if (*head == NULL)
        *tail = NULL;
}


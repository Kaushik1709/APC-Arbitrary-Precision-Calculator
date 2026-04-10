#include "apc.h"


void print_list(Dlist *head)
{
    if (head == NULL)
    {
        printf("0\n");
        return;
    }

    /* skip leading zeros */
    while (head != NULL && head->data == 0)
    {
        head = head->next;
    }

    /* if all digits were zero */
    if (head == NULL)
    {
        printf("0\n");
        return;
    }

    /* print digits */
    while (head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }

    printf("\n");
}
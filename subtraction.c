#include "apc.h"
#include <stdlib.h>

/* Subtraction of two numbers */
int subtraction(Dlist **head1, Dlist **tail1,
                Dlist **head2, Dlist **tail2,
                Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    Dlist *new;

    int borrow = 0;
    int diff;

    /* Initialize result list */
    *headR = NULL;
    *tailR = NULL;

    /* Subtract digits from right to left */
    while (temp1 != NULL)
    {
        diff = temp1->data - borrow;

        /* Subtract second number digit */
        if (temp2 != NULL)
        {
            diff = diff - temp2->data;
            temp2 = temp2->prev;
        }

        /* Handle borrow */
        if (diff < 0)
        {
            diff = diff + 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        /* Create result node */
        new = malloc(sizeof(Dlist));

        if (new == NULL)
        {
            return FAILURE;
        }

        new->data = diff;
        new->prev = NULL;
        new->next = NULL;

        /* Insert result at beginning */
        if (*headR == NULL)
        {
            *headR = new;
            *tailR = new;
        }
        else
        {
            new->next = *headR;
            (*headR)->prev = new;
            *headR = new;
        }

        temp1 = temp1->prev;
    }

    /* Remove leading zeros */
    while (*headR != NULL &&
           (*headR)->data == 0 &&
           (*headR)->next != NULL)
    {
        temp1 = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(temp1);
    }

    return SUCCESS;
}
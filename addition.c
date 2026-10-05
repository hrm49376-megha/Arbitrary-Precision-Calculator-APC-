#include "apc.h"
#include <stdlib.h>

int addition(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR)
{
    /* Definition goes here */
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    Dlist *new;

    int carry = 0;
    int sum;

    *headR = NULL;//Initialize result list
    *tailR = NULL;

    /* Add digits from right to left */
    while (temp1 != NULL || temp2 != NULL)
    {
        sum = carry;

        if (temp1 != NULL)
        {
            sum = sum + temp1->data;
            temp1 = temp1->prev;
        }

        if (temp2 != NULL)
        {
            sum = sum + temp2->data;
            temp2 = temp2->prev;
        }

        carry = sum / 10;

        /* Create result node */
        new = malloc(sizeof(Dlist));

        if (new == NULL)
        {
            return FAILURE;
        }

        new->data = sum % 10;
        new->prev = NULL;
        new->next = NULL;

        /* Insert at beginning */
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
    }

    /* Add remaining carry */
    if (carry != 0)
    {
        new = malloc(sizeof(Dlist));

        if (new == NULL)
        {
            return FAILURE;
        }

        new->data = carry;
        new->prev = NULL;
        new->next = *headR;

        if (*headR != NULL)
        {
            (*headR)->prev = new;
        }

        *headR = new;
    }

    return SUCCESS;
}
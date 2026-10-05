#include "apc.h"
#include <stdlib.h>

int division(Dlist **head1, Dlist **tail1,
             Dlist **head2, Dlist **tail2,
             Dlist **headR, Dlist **tailR)
{
    Dlist *temp1 = *head1;
    Dlist *new;
    long long num1 = 0;
    long long num2 = 0;
    long long result;

    /* Convert first number */
    while (temp1 != NULL)
    {
        num1 = num1 * 10 + temp1->data;
        temp1 = temp1->next;
    }

    /* Convert second number */
    temp1 = *head2;

    while (temp1 != NULL)
    {
        num2 = num2 * 10 + temp1->data;
        temp1 = temp1->next;
    }

    /* Check division by zero */
    if (num2 == 0)
    {
        return FAILURE;
    }

    result = num1 / num2;

    *headR = NULL;
    *tailR = NULL;

    /* Store zero result */
    if (result == 0)
    {
        new = malloc(sizeof(Dlist));

        if (new == NULL)
            return FAILURE;

        new->data = 0;
        new->prev = NULL;
        new->next = NULL;

        *headR = new;
        *tailR = new;

        return SUCCESS;
    }

    /* Store result in reverse order */
    while (result > 0)
    {
        new = malloc(sizeof(Dlist));

        if (new == NULL)
            return FAILURE;

        new->data = result % 10;
        new->prev = NULL;
        new->next = NULL;

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

        result = result / 10;
    }

    return SUCCESS;
}
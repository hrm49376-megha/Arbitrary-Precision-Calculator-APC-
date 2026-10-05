#include "apc.h"
#include <stdio.h>
#include <stdlib.h>

/* Multiplication of two numbers */
int multiplication(Dlist **head1, Dlist **tail1,
                   Dlist **head2, Dlist **tail2,
                   Dlist **headR, Dlist **tailR)
{
    Dlist *temp1;
    Dlist *temp2;
    Dlist *new;

    int count1 = 0;
    int count2 = 0;
    int i, j;
    int *num1;
    int *num2;
    int *result;
    int size;

    /* Count digits in first number */
    temp1 = *head1;

    while (temp1 != NULL)
    {
        count1++;
        temp1 = temp1->next;
    }

    /* Count digits in second number */
    temp2 = *head2;

    while (temp2 != NULL)
    {
        count2++;
        temp2 = temp2->next;
    }

    /* Check for empty lists */
    if (count1 == 0 || count2 == 0)
    {
        return FAILURE;
    }

    /* Allocate memory for arrays */
    num1 = malloc(count1 * sizeof(int));
    num2 = malloc(count2 * sizeof(int));

    if (num1 == NULL || num2 == NULL)
    {
        free(num1);
        free(num2);
        return FAILURE;
    }

    /* Copy first list into array */
    temp1 = *head1;
    i = 0;

    while (temp1 != NULL)
    {
        num1[i] = temp1->data;
        i++;
        temp1 = temp1->next;
    }

    /* Copy second list into array */
    temp2 = *head2;
    i = 0;

    while (temp2 != NULL)
    {
        num2[i] = temp2->data;
        i++;
        temp2 = temp2->next;
    }

    /* Result can have maximum count1 + count2 digits */
    size = count1 + count2;

    result = calloc(size, sizeof(int));

    if (result == NULL)
    {
        free(num1);
        free(num2);
        return FAILURE;
    }

    /* Multiply each digit */
    for (i = count1 - 1; i >= 0; i--)
    {
        for (j = count2 - 1; j >= 0; j--)
        {
            result[i + j + 1] =
                result[i + j + 1] + num1[i] * num2[j];
        }
    }

    /* Handle carry */
    for (i = size - 1; i > 0; i--)
    {
        result[i - 1] = result[i - 1] + result[i] / 10;
        result[i] = result[i] % 10;
    }

    /* Initialize result list */
    *headR = NULL;
    *tailR = NULL;

    /* Remove leading zeros */
    i = 0;

    while (i < size - 1 && result[i] == 0)
    {
        i++;
    }

    /* Create result linked list */
    for (; i < size; i++)
    {
        new = malloc(sizeof(Dlist));

        if (new == NULL)
        {
            free(num1);
            free(num2);
            free(result);
            return FAILURE;
        }

        new->data = result[i];
        new->prev = NULL;
        new->next = NULL;

        /* Insert at last */
        if (*headR == NULL)
        {
            *headR = new;
            *tailR = new;
        }
        else
        {
            new->prev = *tailR;
            (*tailR)->next = new;
            *tailR = new;
        }
    }

    /* Free temporary memory */
    free(num1);
    free(num2);
    free(result);

    return SUCCESS;
}
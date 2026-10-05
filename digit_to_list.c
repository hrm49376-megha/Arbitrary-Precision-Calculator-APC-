#include "apc.h"
#include <stdlib.h>

static void insert_at_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));

    if (new == NULL)
    {
        return;
    }

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if (*head == NULL)
    {
        *head = new;
        *tail = new;
    }
    else
    {
        new->prev = *tail;
        (*tail)->next = new;
        *tail = new;
    }
}

void digit_to_list(Dlist **head1, Dlist **tail1,
                   Dlist **head2, Dlist **tail2,
                   char *argv[])
{
    int i = 0;

    /* Skip sign of first operand */
    if (argv[1][0] == '+' || argv[1][0] == '-')
    {
        i = 1;
    }

    while (argv[1][i] != '\0')
    {
        insert_at_last(head1, tail1, argv[1][i] - '0');
        i++;
    }

    i = 0;

    /* Skip sign of second operand */
    if (argv[3][0] == '+' || argv[3][0] == '-')
    {
        i = 1;
    }

    while (argv[3][i] != '\0')
    {
        insert_at_last(head2, tail2, argv[3][i] - '0');
        i++;
    }
}
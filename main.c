/*
Project Documentation

Project Title: Arbitrary Precision Calculator
Submitted By:

Name: Megha H R
Start Date: 27/08/2026
End Date: 05/09/2026


Objective:

The objective of this project is to perform arithmetic operations on very large
numbers that cannot be stored using normal C data types such as int, long or
long long. The project implements an Arbitrary Precision Calculator using
Doubly Linked Lists to store and process each digit of the operands.


Description:

An Arbitrary Precision Calculator (APC) is a calculator that can perform
arithmetic operations on numbers of any size, limited only by available memory.

In this project, each digit of a large number is stored as a node in a
Doubly Linked List. This allows the program to perform calculations on numbers
that exceed the storage capacity of standard C integer data types.

The project supports four arithmetic operations:

Addition (+): Adds two large numbers.
Subtraction (-): Subtracts one large number from another.
Multiplication (*): Multiplies two large numbers.
Division (/): Divides one large number by another.


Features:

Supports very large integer values.
Uses Doubly Linked Lists to store digits.
Supports Addition of large numbers.
Supports Subtraction of large numbers.
Supports Multiplication of large numbers.
Supports Division of large numbers.
Handles numbers beyond the range of standard integer data types.
Uses command-line arguments to receive operands and operators.
Stores the final result in a separate Doubly Linked List.
Displays the calculated result correctly.


Data Structure Used:

Doubly Linked List

Each node contains:

prev  -> Address of previous node
data  -> Single digit of the number
next  -> Address of next node


Structure:

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} Dlist;


Algorithm:

Addition:

1. Store the first and second operands in separate Doubly Linked Lists.
2. Start processing digits from the least significant digit.
3. Add corresponding digits from both lists.
4. Add the carry from the previous operation.
5. Store the result digit in the result list.
6. Continue until all digits are processed.
7. If a carry remains, insert it into the result list.
8. Display the result.


Subtraction:

1. Store both operands in separate Doubly Linked Lists.
2. Compare the two numbers to determine the larger operand.
3. Start processing digits from the least significant digit.
4. Subtract the corresponding digits along with the borrow.
5. If the digit of the first number is smaller, borrow from the next digit.
6. Store the calculated digit in the result list.
7. Continue until all digits are processed.
8. Remove unnecessary leading zeros.
9. Display the result with the appropriate sign if required.


Multiplication:

1. Store both operands in separate Doubly Linked Lists.
2. Process the digits from right to left.
3. Multiply each digit of the first operand with every digit of the second operand.
4. Store the intermediate results in the result structure.
5. Handle carry values after multiplication.
6. Store the final digits in the result Doubly Linked List.
7. Display the result.


Division:

1. Store the dividend and divisor in separate Doubly Linked Lists.
2. Check whether the divisor is zero.
3. Compare the dividend with the divisor.
4. Perform division using repeated subtraction or long-division logic.
5. Store the quotient in the result Doubly Linked List.
6. Continue until the complete dividend is processed.
7. Display the quotient.
8. Handle division by zero appropriately.


Command Line Usage:

The calculator accepts three command-line arguments:
./apc <operand1> <operator> <operand2>


Examples:

Addition:
./apc 12345 + 98785

Subtraction:
./apc 987654 - 123456

Multiplication:
./apc 12345 '*' 67890

Division:
./apc 12345 '/' 123


Conclusion:

The Arbitrary Precision Calculator successfully performs arithmetic operations
on very large numbers using Doubly Linked Lists. The project demonstrates the
practical use of dynamic memory allocation, linked lists, pointers, functions,
command-line arguments and arithmetic algorithms in C.

This project helps in understanding how large numbers can be processed without
depending on the limitations of standard integer data types.
*/


#include "apc.h"
#include <stdio.h>

/* Main function */
int main(int argc, char *argv[])
{
    /* Declare operand and result lists */
    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *headR = NULL, *tailR = NULL;
    Dlist *temp;
    char operator;

    /* Check command-line arguments */
    if (argc != 4)
    {
        printf("Usage: ./APC.out <operand1> <operator> <operand2>\n");
        return FAILURE;
    }

    /* Get the operator */
    operator = argv[2][0];

    /* Select the operation */
    switch (operator)
    {
        case '+':
            /* Convert operands into linked lists */
            digit_to_list(&head1, &tail1, &head2, &tail2, argv);

            /* Perform addition */
            addition(&head1, &tail1, &head2, &tail2,
                     &headR, &tailR);
            break;

        case '-':
            /* Convert operands into linked lists */
            digit_to_list(&head1, &tail1, &head2, &tail2, argv);

            /* Perform subtraction */
            subtraction(&head1, &tail1, &head2, &tail2,
                        &headR, &tailR);
            break;

        case 'x':
        case '*':
            /* Convert operands into linked lists */
            digit_to_list(&head1, &tail1, &head2, &tail2, argv);

            /* Perform multiplication */
            multiplication(&head1, &tail1, &head2, &tail2,
                           &headR, &tailR);
            break;

        case '/':
            /* Convert operands into linked lists */
            digit_to_list(&head1, &tail1, &head2, &tail2, argv);

            /* Perform division */
            division(&head1, &tail1, &head2, &tail2,
                     &headR, &tailR);
            break;

        default:
            /* Handle invalid operator */
            printf("Invalid Input:-( Try again...\n");
            return FAILURE;
    }

    /* Print the result */
    temp = headR;

    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }

    printf("\n");

    return SUCCESS;
}
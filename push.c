#include "monty.h"
/**
 * op_push - push an element to the stack
 * @stack: pointer to the head of the stack
 * @line_number: line number
 * Return: void
 */

void op_push(stack_t **stack, unsigned int line_number)
{
    stack_t *new_node;
    char *n;
    int i;

    n = strtok(NULL, "\n");
    if (n == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
    for (i = 0; n[i]; i++)
    {
        if (n[i] == '-' && i == 0)
            continue;
        if (isdigit(n[i]) == 0)
        {
            fprintf(stderr, "L%d: usage: push integer\n", line_number);
            exit(EXIT_FAILURE);
        }
    }

    new_node = (stack_t*)malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = atoi(n);
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;
    *stack = new_node;
}
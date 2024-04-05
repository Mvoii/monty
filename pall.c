#include "monty.h"
/**
 * get_instruction - get instruction
 * @line: line to parse
 * @line_number: line number
 * Return: instruction
 */

void op_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;
     
    temp = *stack;

    while (temp != NULL)
    {
        printf("%d\n", temp->n);
        temp = temp->next;
    }
}
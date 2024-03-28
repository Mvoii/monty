#include "monty.h"

/**
 * main - entry point
 * @argc: argument counter
 * @argv: argument vector
 * Return: success || failure
 */
int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    stack_t *stack = NULL;
    unsigned int line_number = 0;
    instruction_t instruction;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
        instruction = get_instruction(line, line_number);
        if (instruction.opcode == NULL)
            continue;
        instruction.opcode(&stack, line_number);
    }
    free(line);
    free_stack(stack);
    fclose(file);
    exit(EXIT_SUCCESS);
}
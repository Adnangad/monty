#include "main.h"

/**
 * push - adds element to stack
 * @stack:the stack
 * @value:the value
 * 
 * Return:None
 */
void push(stack_t **stack, int value)
{
    stack_t *new = malloc(sizeof(stack_t));

    if (new == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        if (*stack == NULL)
        {
            new->n = value;
            new->prev = NULL;
            new->next = NULL;
            *stack = new;
        }
        else
        {
            new->n = value;
            new->prev = NULL;
            new->next = *stack;
            *stack = new;
        }
    }
}

/**
 * pall:prints the elements in the stack
 * @stack:contains elements to be printed
 *
 * Return:none
 */
void pall(stack_t **stack)
{
    stack_t *point = *stack;

    if (point == NULL)
    {
        fprintf(stderr, "Error, stack underflow\n");
    }
    else
    {
        while (point != NULL)
        {
            printf("%d\n", point->n);
            point = point->next;
        }
    }
}

/**
 * interpreter - languange interprator
 * @file_path:the file to be read
 *
 * Return:none
 */
void interpreter(const char *file_path)
{
    char line[100];
    stack_t *stack = NULL;
    char *val_str;
    char *opcode, *token;
    unsigned int line_number = 0;
    int val;
    FILE *file = fopen(file_path, "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", file_path);
        exit(EXIT_FAILURE);
    }
    else
    {
        while (fgets(line, sizeof(line), file))
        {
            line_number++;
            opcode = strtok(line, "\n");

            if (opcode != NULL)
            {
                token = strtok(opcode, " ");

                if (token != NULL)
                {
                    if (strcmp(token, "push") == 0)
                    {
                        val_str = strtok(NULL, "\n");

                        if (val_str == NULL)
                        {
                            fprintf(stderr, "L%d: usage: push integer\n", line_number);
                            exit(EXIT_FAILURE);
                        }
                        val = atoi(val_str);
                        push(&stack, val);
                    }
                    else if (strcmp(token, "pall") == 0)
                    {
                        pall(&stack);
                    }
                    else
                    {
                        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
                        exit(EXIT_FAILURE);
                    }
                }
            }
        }
    }
    fclose(file);
}

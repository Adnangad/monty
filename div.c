#include "monty.h"

/**
 * divide - div elements of top 2
 * @stack:the stack
 * @line_number:line number
 *
 * Return:None
 */
void divide(stack_t **stack, unsigned int line_number)
{
        stack_t *p;
        int rez;

        p = *stack;

        if (p == NULL || p->next == NULL)
        {
                fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        rez = p->next->n / p->n;
        p->next->n = rez;
        *stack = p->next;
        free(p);
}

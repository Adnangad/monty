#include "monty.h"

/**
 * mod - div elements of top 2
 * @stack:the stack
 * @line_number:line number
 *
 * Return:None
 */
void mod(stack_t **stack, unsigned int line_number)
{
        stack_t *p;
        int rez;

        p = *stack;

        if (p == NULL || p->next == NULL)
        {
                fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        if (p->n == 0)
        {
                fprintf(stderr, "L%d: division by zero\n", line_number);
                exit(EXIT_FAILURE);
        }
        rez = p->next->n % p->n;
        p->next->n = rez;
        *stack = p->next;
        free(p);
}

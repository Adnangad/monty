#include "monty.h"

/**
 * pop - removes top element
 * @stack:the stack
 * @line_number:the number
 *
 * Return:None
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *p;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	p = *stack;
	*stack = (*stack)->next;
	free(p);
}


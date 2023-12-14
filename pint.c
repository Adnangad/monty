#include "monty.h"

/**
 * f_pint - prints value at top of stack
 * @stack:the stack
 * @line_number:the line number
 *
 * Return:none
 */
void f_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *p;
	p = *stack;

	if (p == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", p->n);
}

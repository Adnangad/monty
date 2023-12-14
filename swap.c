#include "monty.h"

/**
 * swap - swaps value of two elements
 * @stack:the stack
 * @line_number:irelevant
 *
 * Return:None
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;
	stack_t *p = *stack;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = p->n;
	p->n = p->next->n;
	p->next->n = temp;
}

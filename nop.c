#include "monty.h"

/**
 * nop - does nothing
 * @stack:nothing
 * @line_number:nothing
 *
 * Return:NONE
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)*stack;
	(void)line_number;
}

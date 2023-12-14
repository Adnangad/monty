#include "monty.h"

/**
 * push - adds element to stack
 * @stack:the tstack
 * @line_number:the line number
 *
 * Return:none
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *val_str;
	int val;
	stack_t *new;

	val_str = strtok(NULL, "\n");

	if (val_str == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	val = atoi(val_str);
	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (*stack == NULL)
	{
		new->n = val;
		new->next = NULL;
		new->prev = NULL;
		*stack = new;
	}
	else
	{
		new->n = val;
		new->prev = NULL;
		new->next = *stack;
		*stack = new;
	}
}
/**
 * pall - prints all
 * @stack:stack to be printed
 * @line_number:irelevant
 *
 * Return:None
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *p;
	(void) line_number;
	p = *stack;

	if (p == NULL)
	{
		return;
	}
	while (p != NULL)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}

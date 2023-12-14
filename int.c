#include "monty.h"

/**
 * interpreter - reads and executes functions
 * @file_path:holds the functions
 *
 * Return:None
 */
void interpreter(const char *file_path)
{
	instruction_t inst[] = {
		{"push", push},
		{"pall", pall},
		{"pint", f_pint},
		{NULL, NULL}
	};
	char line[100];
	stack_t *stack = NULL;
	char *opcode;
	unsigned int line_number = 0;
	int val;
	size_t i;
	FILE *file = fopen(file_path, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_path);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		opcode = strtok(line, " \n");

		if (opcode != NULL)
		{
			val = 0;

			for (i = 0; inst[i].opcode != NULL; i++)
			{
				if (strcmp(opcode, inst[i].opcode) == 0)
				{
					inst[i].f(&stack, line_number);
					val = 1;
					break;
				}
			}
			if (!val)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				exit(EXIT_FAILURE);
			}
		}
	}
	fclose(file);
}

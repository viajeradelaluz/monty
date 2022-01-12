#include "monty.h"

/**
 * get_instructions - 
 * @stack:
 * @line_number:
 * Return: no return.
 */
void (*get_instructions(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t op_list[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add},
		{NULL, nop}
	};

	int i = 0;
	while (op_list[i].opcode)
	{
		if (strcmp(opcode, op_list[i].opcode) == 0)
			return (op_list[i].f);
		i++;
	}

	return (nop);
}

#include "monty.h"

/**
 * pstr - Print the string startingat at the top of the stack.
 * @head: head of the double linked list.
 * @line_number: number of the lines.
 */
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *node = NULL;
	(void)line_number;

	node = *head;
	if (!node)
		fprintf(stderr, "\n");

	while (node)
	{
		if (node->n >= 33 && node->n <= 126)
			fprintf(stdout, "%c", node->n);
		else
			break;

		node = node->next;
	}
	fprintf(stdout, "\n");
}
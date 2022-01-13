#include "monty.h"

/**
 * pstr - Print the string startingat at the top of the stack.
 * @head: head of the double linked list.
 * @line_number: number of the lines.
 */
void pstr(stack_t **head, unsigned int line_number)
{
	stack_t *current = NULL;
	(void)line_number;

	current = *head;
	if (!current)
	{
		fprintf(stdout, "\n");
		return;
	}
	while (current)
	{
		if (current->n >= 33 && current->n <= 126)
			fprintf(stdout, "%c", current->n);
		else
			break;

		current = current->next;
	}
	fprintf(stdout, "\n");
}
/**
 * rotl - The top element of the stack becomes the last one.
 * @head: head of the double linked list.
 * @line_number: number of the lines.
 */
void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *current = NULL;
	(void)line_number;

	current = *head;
	if (!current)
		return;
	add_node_end(head, current->n);
	pop(head, line_number);
	current = NULL;
}


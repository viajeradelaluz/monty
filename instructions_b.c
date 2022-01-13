#include "monty.h"

/**
 * pop - adds at first position in a stack
 *
 * @head: header of the stack
 * @line_number: number of lines
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *node = NULL;

	if (!head || !*head)
	{
		fprintf(stderr, ERROR_POP, line_number);
		free_stack(*head), fclose(monty_data);
		exit(EXIT_FAILURE);
	}
	node = *head;
	*head = (*head)->next;
	free(node);
	if (*head)
		(*head)->prev = NULL;
}

/**
 * swap - swap between nodes positions
 *
 * @head: header of the stack
 * @line_number: number of lines
 */
void swap(stack_t **head, unsigned int line_number)
{
	(void)(**head);
	(void)(line_number);
	printf("Hello, function in progress: swap\n");
}
/**
 * add - add nodes
 *
 * @head: header of the stack
 * @line_number: number of lines
 */
void add(stack_t **head, unsigned int line_number)
{
	(void)(**head);
	(void)(line_number);
	printf("Hello, function in progress: add\n");
}

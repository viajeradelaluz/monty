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
	int node_n = 0;

	if (!head || !*head || !(*head)->next)
	{
		fprintf(stderr, ERROR_SWAP, line_number);
		free_stack(*head), fclose(monty_data);
		exit(EXIT_FAILURE);
	}
	node_n = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = node_n;
}
/**
 * add - add nodes
 *
 * @head: header of the stack
 * @line_number: number of lines
 */
void add(stack_t **head, unsigned int line_number)
{
	if (!head || !*head || !(*head)->next)
	{
		fprintf(stderr, ERROR_ADD, line_number);
		free_stack(*head), fclose(monty_data);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n = (*head)->n + (*head)->next->n;
	pop(head, line_number);
}

#include "monty.h"

/**
 * sub - Substract the value of two nodes.
 * @head: header of the stack.
 * @line_number: number of lines.
 */
void sub(stack_t **head, unsigned int line_number)
{
	if (!head || !*head || !(*head)->next)
	{
		fprintf(stderr, ERROR_MATH, line_number, "sub");
		free_stack(*head), fclose(monty_data);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n -= (*head)->n;
	pop(head, line_number);
}

/**
 * _div - Divide the values of two nodes.
 * @head: head of the double linked list.
 * @line_number: number of the lines.
 */
void _div(stack_t **head, unsigned int line_number)
{
	if (!head || !*head || !(*head)->next)
	{
		fprintf(stderr, ERROR_MATH, line_number, "div");
		free_stack(*head), fclose(monty_data);
		exit(EXIT_FAILURE);
	}

	if (!(*head)->n)
	{
		fprintf(stderr, ERROR_ZERO, line_number);
		free_stack(*head), fclose(monty_data);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n /= (*head)->n;
	pop(head, line_number);
}

/**
 * mul - Multiply the top and the second nodes.
 * @head: head of the double linked list.
 * @line_number: number of the lines.
 */
void mul(stack_t **head, unsigned int line_number)
{
	if (!head || !*head || !(*head)->next)
	{
		fprintf(stderr, ERROR_MATH, line_number, "mul");
		free_stack(*head), fclose(monty_data);
		exit(EXIT_FAILURE);
	}
	(*head)->next->n *= (*head)->n;
	pop(head, line_number);
}

/**
 * mod - Calculate the values of two nodes.
 * @head: head of the double linked list.
 * @line_number: number of the lines.
 */
void mod(stack_t **head, unsigned int line_number)
{
	if (!head || !*head || !(*head)->next)
	{
		fprintf(stderr, ERROR_MATH, line_number, "mod");
		free_stack(*head), fclose(monty_data);
		exit(EXIT_FAILURE);
	}

	if (!(*head)->n)
	{
		fprintf(stderr, ERROR_ZERO, line_number);
		free_stack(*head), fclose(monty_data);
		exit(EXIT_FAILURE);
	}

	(*head)->next->n %= (*head)->n;
	pop(head, line_number);
}

/**
 * pchar - Print the char at he top of the stack.
 * @head: head of the double linked list.
 * @line_number: number of the lines.
 */
void pchar(stack_t **head, unsigned int line_number)
{
	if (!head || !*head)
	{
		fprintf(stderr, ERROR_PCHAR, line_number, "stack empty");
		free_stack(*head), fclose(monty_data);
		exit(EXIT_FAILURE);
	}

	if ((*head)->n >= 33 && (*head)->n <= 126)
		fprintf(stdout, "%c\n", (*head)->n);
	else
	{
		fprintf(stderr, ERROR_PCHAR, line_number, "value out of range");
		free_stack(*head), fclose(monty_data);
		exit(EXIT_FAILURE);
	}
}

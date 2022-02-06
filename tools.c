#include "monty.h"

/**
 * file_to_open - Open a monty file from main arguments.
 * @monty_file: file to open.
 * @argv: arguments passed to main.
 * Return: the file opened.
 */
FILE *open_file(char *monty_file, char *argv[])
{
	monty_file = argv[1];
	monty_data = fopen(monty_file, FO_RDONLY);
	if (!monty_data)
	{
		fprintf(stderr, "Error: Can't open file %s\n", monty_file);
		exit(EXIT_FAILURE);
	}

	return (monty_data);
}

/**
 * parse_line - Parse each line of the monty file.
 * @monty_data: monty file to parse.
 * Return: last line number on the monty file opened.
 */
FILE *parse_line(FILE *monty_data)
{
	char *token = NULL;
	char buffer[BUFSIZ];
	unsigned int line_number = 1;
	void (*get_opcode)(stack_t **, unsigned int);
	stack_t *head = NULL;

	while (fgets(buffer, sizeof(buffer), monty_data) != NULL)
	{
		token = strtok(buffer, DELIM);
		if (!token || token[0] == '#')
		{
			line_number++;
			continue;
		}

		get_opcode = get_operation(token);
		UNKNOWN_OPCODE(head, monty_data, line_number, token, get_opcode);
		get_opcode(&head, line_number);

		line_number++;
	}
	free_stack(head);

	return (monty_data);
}

/**
 * str_isdigit - Check if a string is a digit.
 * @string: string to check.
 * Return: 1 if it is digit 0 if not.
 */
int str_isdigit(char *string)
{
	int i = 0;

	if (!string)
		return (0);

	if (string[i] == '-')
		i++;

	while (string[i])
	{
		if (isdigit(string[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

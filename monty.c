#include "monty.h"

/**
 * main - Program to interprete the command-line.
 * @argc: number of arguments passed to main.
 * @argv: arguments passed to main.
 *
 * Return: always 0 on success, otherwise EXIT_FAILURE.
 */
int main(int argc, char *argv[])
{
	char *monty_file = NULL;
	FILE *monty_data = NULL;

	/*Checks number of arguments*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Open and read the monty file */
	monty_data = open_file(monty_file, argv);
	parse_line(monty_data);

	fclose(monty_data);
	return (0);
}

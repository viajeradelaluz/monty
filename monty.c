#include "monty.h"

/**
 *
 *
 */
int main(int argc, char *argv[])
{
	char *monty_file = NULL, *token = NULL;
	FILE *monty_opened = NULL;
	char buffer[BUFSIZ];

	/*Checks number of arguments*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Open and read the monty file */
	monty_file = argv[1];
	monty_opened = fopen(monty_file, FO_RDONLY);
	if (!monty_opened)
	{
		fprintf(stderr, "Error: Can't open file %s", monty_file);
		exit(EXIT_FAILURE);
	}

	/* Get and parse the lines of the monty file */
	while (fgets(buffer, sizeof(buffer), monty_opened) != NULL)
	{
		token = strtok(buffer, " \n\t");
		while (token != NULL)
		{
			fprintf(stdout, "%s", token);
			token = strtok(NULL, " \n\t");
		}
	}

	fclose(monty_opened);
	return (0);
}

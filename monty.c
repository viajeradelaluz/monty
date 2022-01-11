#include "monty.h"

int main(size_t argc, char *argv[])
{
	char *file_name = NULL;
	int i;
	char buffer[3000];
	char *token = NULL;
	FILE *file_pointer = NULL;


	/*Checks number of arguments*/
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_name = argv[1];
	file_pointer = fopen(file_name, "r");
	if (!file_pointer)
	{
		fprintf(stderr, "Error: Can't open file %s", file_name);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), file_pointer)!= NULL)
	{
		token = NULL;
		token = strtok(buffer, " \n\t");
		while (token != NULL)
		{
			fprintf(stdout, "%s \n", token);

			token = strtok(NULL, " ");
		}		
	}
	
	

	fclose(file_pointer);
	return (0);
}
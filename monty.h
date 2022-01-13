#ifndef _MONTY_LIB_
#define _MONTY_LIB_

/* LIBS */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <string.h>
#include <ctype.h>

/* MACROS AND EXTERN VARS */

#define FO_RDONLY "r"
#define DELIM " \n\t"
#define ERROR_PUSH "L%d: usage: push integer\n"
#define ERROR_PINT "L%d: can't pint, stack empty\n"
#define ERROR_POP "L%d: can't pop an empty stack\n"
#define ERROR_SWAP "L%d: can't swap, stack too short\n"
extern FILE *monty_data;

#define UNKNOWN_OPCODE(HEAD, MONTY_DATA, LINE_NUMBER, TOKEN, GET_OPCODE)\
do {\
	if (!GET_OPCODE)\
	{\
		free_stack(HEAD), fclose(MONTY_DATA);\
		fprintf(stderr, "L%d: unknown instruction %s\n", LINE_NUMBER, TOKEN);\
		exit(EXIT_FAILURE);\
	} \
} while (0)

/* STRUCTS DEFINITIONS */

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* FUNCTIONS IN TOOLS */

FILE *open_file(char *monty_file, char *argv[]);
FILE *parse_line(FILE *monty_data);
int str_isdigit(char *string);

/* FUNCTIONS IN INSTRUCTIONS A, B */

void push(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);

/* FUNCTIONS IN STACK_OPERATIONS */

stack_t *add_new_node(stack_t **head, int data_node);
void free_stack(stack_t *head);

/* FUNCTION IN GET_OPCODE */

void (*get_operation(char *opcode))(stack_t **stack, unsigned int line_number);

#endif /*_MONTY_LIB_*/

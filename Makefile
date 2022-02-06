#	Compilation Rules 
#	gcc -Wall -Werror -pedantic -Wextro -g -std=gnu89

CC = gcc
CFLAG = -Wall -Werror -pedantic -Wextra -std=gnu89 -ggdb

monty:
	$(CC) $(CFLAG) -g *.h *.c -o monty
clean:
	rm -r monty
#	Compliation Rules 
#	gcc -Wall -Werror -pedantic -Wextro -g -std=gnu89

CC = gcc
CFLAG = -Wall -Werror -pedantic -Wextra -std=gnu89 -ggdb

monty:
	$(CC) $(CFLAG) -g *.c -o monty_alpha_v0.1
monty_unclean:
	$(CC) -g *.c -o monty_alpha_v0.1
clean:
	rm -r monty_alpha_v0.1
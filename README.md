# The Monty Program

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty Bytecode files

Files containing Monty byte codes usually have the `.m` extension:

```sh
foo@holberton:~/monty$ cat file.m
# Push and print elements to the stack or queue
push 1
push 2
push 3
pall
foo@holberton:~/monty$
```

## How to use

Usage:  `./monty file.m` where  `file.m` is the path to the file containing Monty Bytecode.

### Requirements

Compile all `*.c` and `*.h` files using GNU Compiler Collection (GCC) and run under linux environments like `Ubuntu 20.04 LTS`.

```sh
foo@holberton:~/monty$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.h *.c -o monty
```

### The magic of Makefile:

You can compile and run the *monty program* with the Makefile using the command below.

```sh
foo@holberton:~/monty$ make monty
foo@holberton:~/monty$ ./monty file.m
3
2
1
foo@holberton:~/monty$
```

## File Description

- ``Makefile`` — Script to compilate and run the program.
- ``README.md`` — Project's description.
- ``get_opcode.c`` — List of main opcodes available to execute under the monty program.
- ``instructions*.c`` — Instructions to execute for each opcode. 
- ``monty.c`` — Main track process of the program. Where the input line is readed, the arguments are parsed and the commands are executed.
- ``main.h`` — Main libraries that allow the compilation of the program.
- ``stack_operations.c`` — Functions to handle stack and queue linked lists.
- ``tools.c`` — Functions behind the execution of the `monty.c` file. 

## Authors

Johanna Alfonso | Daniel Cerón

## More information

[Holberton School](https://www.holbertonschool.com/)

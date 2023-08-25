# MONTY
**0x19. C - Stacks, Queues - LIFO, FIFO**

The Monty language - Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Usage: **monty file** where file is the path to the file containing Monty byte code.

If the user does not give any file or more than one argument to your program, print the error message **USAGE: monty file**, followed by a new line, and exit with the status **EXIT_FAILURE**

If, for any reason, it’s not possible to open the file, print the error message **Error: Can't open file <file>**, followed by a new line, and exit with the status **EXIT_FAILURE**
where **<file>** is the name of the file.

If the file contains an invalid instruction, print the error message **L<line_number>: unknown instruction <opcode>**, followed by a new line, and exit with the status **EXIT_FAILURE**
where is the line number where the instruction appears. Line numbers always start at 1.

The monty program runs the bytecodes line by line and stop if either: it executed properly every line of the file, it finds an error in the file, an error occured. 

If you can’t malloc anymore, print the error message **Error: malloc failed**, followed by a new line, and exit with status **EXIT_FAILURE.**

You have to use malloc and free and are not allowed to use any other function from man malloc (realloc, calloc, …)

**This project aims to learn the following:**

What do LIFO and FIFO mean.

What is a stack, and when to use it.

What is a queue, and when to use it.

What are the common implementations of stacks and queues.

What are the most common use cases of stacks and queues.

What is the proper way to use global variables.

**Requirements**

The code is compiled using: gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty

Any output must be printed on stdout

Any error message must be printed on stderr

**TASKS**

* monty.h

This is the header file with the prototypes of all functions. Including the data structures that have been provided.





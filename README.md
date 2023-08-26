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

* opcode.c

Parsing and executing the opcode instructions that are read from the input file, ensuring the operations are performed are performed on the stack.

* pushpal.c

  Implement the push and pall opcodes.

The opcode push pushes an element to the stack where Usage: push <int> where <int> is an integer. if <int> is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE where is the line number in the file. You won’t have to deal with overflows. Use the atoi function

The opcode pall prints all the values on the stack, starting from the top of the stack. If the stack is empty, don’t print anything.

* pint.c

Implement the pint opcode. The opcode pint prints the value at the top of the stack, followed by a new line. If the stack is empty, print the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE.

* pop.c

Implement the pop opcode. The opcode pop removes the top element of the stack. If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE.

* swap.c

Implement the swap opcode. The opcode swap swaps the top two elements of the stack. If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE.

* add.c

Implement the add opcode. The opcode add adds the top two elements of the stack. If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE. The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

The top element of the stack contains the result

The stack is one element shorter

* nop.c

Implement the nop opcode. The opcode nop doesn’t do anything.

* sub.c

Implement the sub opcode. The opcode sub subtracts the top element of the stack from the second top element of the stack. If the stack contains less than two elements, print the error message L<line_number>: can't sub, stack too short, followed by a new line, and exit with the status EXIT_FAILURE. The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

The top element of the stack contains the result

The stack is one element shorter

* div.c

Implement the div opcode. The opcode div divides the second top element of the stack by the top element of the stack. If the stack contains less than two elements, print the error message L<line_number>: can't div, stack too short, followed by a new line, and exit with the status EXIT_FAILURE.

The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

The top element of the stack contains the result

The stack is one element shorter

If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE.

* mul.c

Implement the mul opcode. The opcode mul multiplies the second top element of the stack with the top element of the stack. If the stack contains less than two elements, print the error message L<line_number>: can't mul, stack too short, followed by a new line, and exit with the status EXIT_FAILURE. The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

The top element of the stack contains the result

The stack is one element shorter

* mod.c

Implement the mod opcode. The opcode mod computes the rest of the division of the second top element of the stack by the top element of the stack. If the stack contains less than two elements, print the error message L<line_number>: can't mod, stack too short, followed by a new line, and exit with the status EXIT_FAILURE. The result is stored in the second top element of the stack, and the top element is removed, so that at the end:

The top element of the stack contains the result

The stack is one element shorter

If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE.

**END**

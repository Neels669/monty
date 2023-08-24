#include "monty.h"

/**
 * pint_op - Prints the value at the top of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number where the instruction appears.
 *
 * Return: Nothing
 */
void pint_op(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

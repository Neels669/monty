#include "monty.h"

/**
 * sub_op - Subtracts the top element from the second top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number where the instruction appears.
 *
 * Return: Nothing
 */
void sub_op(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;

	second = (*stack)->next;

	second->n -= first->n;

	pop_op(stack, line_number);
}

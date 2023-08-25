#include "monty.h"

/**
 * mul_op - Multiplies the second top element by the top element of the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number where the instruction appears.
 *
 * Return: Nothing
 */
void mul_op(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;

	second = (*stack)->next;

	second->n *= first->n;

	pop_op(stack, line_number);
}

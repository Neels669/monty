#include "monty.h"

/**
 * _atoi - Checks if a string is a valid integer.
 * @str: String to check.
 *
 * Return: 1 if the string is an integer, 0 otherwise.
 */
int _atoi(char *str)
{
	int i;

	i = 0;

	if (!str)
	{
		return (0);
	}

	if (str[0] == '-')
	{
		i = 1;
	}

	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}

	return (1);
}

/**
 * push_op - Pushes an element onto the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number where the instruction appears.
 *
 * Return: Nothing
 */
void push_op(stack_t **stack, unsigned int line_number)
{
	char *arg = strtok(NULL, " \n\t");
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!arg || !_atoi(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(arg);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall_op - Prints all the values on the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number where the instruction appears.
 *
 * Return: Nothing
 */
void pall_op(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

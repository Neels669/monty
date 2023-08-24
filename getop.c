#include "monty.h"

/**
 * stderr_unknown - unknown error messagess.
 * @line_number: line number of the instruction.
 * @token: type pointer char of the instruction.
 * Return: EXIT_FAILURE
 */
void stderr_unknown(char *token, unsigned int line_number)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
	exit(EXIT_FAILURE);
}

/**
 * get_builtin - Parses the instruction with the function.
 * @token: type pointer extern var char
 * @stack: type pointer node of data struct
 * @line_number: line of instructions
 *
 * Return: Retunr the funtion
 */
int get_builtin(char *token, stack_t **stack, unsigned int line_number)
{
	instruction_t op_built[] = {
		{ "push", push_op },
		{ "pall", pall_op},
		{ "pint", pint_op },
		{ "pop", pop_op },
		{ NULL, NULL }
	};
	int i, flag = 0;
	char *argumentos = NULL;

	if (stack == NULL || token == NULL)
		return (0);
	argumentos = token;
	for (i = 0; op_built[i].opcode; i++)
	{
		if (strcmp(argumentos, op_built[i].opcode) == 0)
		{
			flag = 1;
			op_built[i].f(stack, line_number);
			break;
		}
	}
	if (flag == 0)
		stderr_unknown(token, line_number);
	return (0);
}

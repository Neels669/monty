#include "monty.h"

/**
 * main - Start
 * @argc: Argument count
 * @argv: argument vector
 *
 * Return: success
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	char *line = NULL;
	unsigned int line_number = 0;
	FILE *file;
	char *opcode;
	char buffer[1024];

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), file))
	{
		line_number++;

		opcode = strtok(buffer, " \n\t");

		if (opcode)
		{
			get_builtin(opcode, &stack, line_number);
		}
	}
	free(line);
	fclose(file);
	while (stack)
	{
		stack_t *temp = stack;

		stack = stack->next;
		free(temp);
	}
	return (EXIT_SUCCESS);
}

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
	size_t len = 0;
	unsigned int line_number = 0;
	char *opcode = strtok(line, " \n\t");
	int valid_instruction = 0;
	FILE *file;
	int i;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return EXIT_FAILURE;
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return EXIT_FAILURE;
	}

	while (getline(&line, &len, file) != -1)
	{
		line_number++;

		if (opcode)
		{
			for (i = 0; instructions[i].opcode; i++)
			{
				if (strcmp(opcode, instructions[i].opcode) == 0)
				{
					valid_instruction = 1;
					instructions[i].f(&stack, line_number);
					break;
				}
			}

			if (!valid_instruction)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
				free(line);
				fclose(file);
				while (stack)
				{
					stack_t *temp = stack;
					stack = stack->next;
					free(temp);
				}
				return EXIT_FAILURE;
			}
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

	return EXIT_SUCCESS;
}

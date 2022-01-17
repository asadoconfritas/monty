#include "monty.h"

/**
 * main - monty main
 * @argc: n of args
 * @argv: all args
 * Return: end program
 **/
int main(int argc, char **argv)
{
	FILE *arch;
	char *zbuffer = NULL;
	size_t sizet = 1024;
	unsigned int line_number = 1;
	int xdgetl = 0;
	stack_t *stack = NULL;
	instruction_t comms[6] = {{"pint", zpint}, {"pall", zpall}, {"push", zpush},
	{"pop", zpop}, {"swap", zswap}, {"add", zadd}};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	arch = fopen(argv[1], "r");
	if (!arch)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		xdgetl = getline(&zbuffer, &sizet, arch);
		if (xdgetl == EOF)
			break;
		part2(strtok(zbuffer, " \t"), &comms, line_number, &stack);
		line_number++;
	}
	zfree(&stack);
	if (zbuffer)
		free(zbuffer);
	if (arch)
		free(arch);
	return (EXIT_SUCCESS);
}

/**
 * part2 - of the main process
 * @zbuffer: related to the process
 * @comms: possible commands
 * @line_number: line counter
 * @stack: pointer
 * Return: void
 **/
void part2(char *zbuffer, instruction_t (*comms)[], unsigned int line_number,
stack_t **stack)
{
	int len = strlen(zbuffer);
	int cursor;

	if (zbuffer[len - 1] == '\n')
		zbuffer[len - 1] = 0;
	if (!strcmp(zbuffer, ""))
		return;
	if (!strcmp(zbuffer, "nop"))
		return;
	if (zbuffer[0] == '#')
		return;

	for (cursor = 0; cursor < 6; cursor++)
	{
		if (!strcmp(zbuffer, (*comms)[cursor].opcode))
		{
			(*comms)[cursor].f(stack, line_number);
			return;
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s", line_number, zbuffer);
	exit(EXIT_FAILURE);
}

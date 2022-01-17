#include "monty.h"

/**
 * zpall - prints all values
 * @stack: pointer
 * @line_number: n of line
 * Return: end program
 **/
void zpall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;
	(void)line_number;

	while (tmp)
	{
		fprintf(stdout, "%d\n", (tmp)->n);
		tmp = (tmp)->next;
	}
}

/**
 * zpush - pushes an element
 * @stack: pointer
 * @line_number: n of line
 * Return: end program
 **/
void zpush(stack_t **stack, unsigned int line_number)
{
	char *astring;
	int n = 0;

	astring = strtok(NULL, " ");
	if (astring == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	n = atoi(astring);
	if (global.mode == 1)

}

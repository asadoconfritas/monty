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
	stack_t *aux;
	char *nstring;

	nstring = strtok(NULL, " ");
	zpushaux(nstring, stack, line_number);
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	aux->n = atoi(nstring);
	aux->prev = NULL;
	aux->next = NULL;
	if (!(stack))
	{
		*stack = aux;
		return;
	}
	aux->next = *stack;
	(*stack)->prev = aux;
	*stack = aux;
}

/**
 * zpushaux - arg n
 * @nstring: of opcode
 * @stack: pointer
 * @line_number: n of line
 * Return: end program
 **/
void zpushaux(char *nstring, stack_t **stack, unsigned int line_number)
{
	int i = 0;

	if (!nstring)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		zfree(stack);
		exit(EXIT_FAILURE);
	}
	if (nstring[0] == '-')
		i++;
	for (; nstring[i]; i++)
	{
		if (nstring[i] >= '0' && nstring[i] <= '9')
			continue;
		else
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			zfree(stack);
			exit(EXIT_FAILURE);
		}
	}
}

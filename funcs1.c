#include "monty.h"

/**
 * zswap - pswap func
 * @stack: pointer
 * @line_number: n of lines
 **/
void zswap(stack_t **stack, unsigned int line_number)
{
	int iaux = 0, len = 0;
	stack_t *aux;

	aux = *stack;

	while (aux)
	{
		len++;
		aux = aux->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	iaux = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = iaux;

}

/**
 * zpop - pop func
 * @stack: pointer
 * @line_number: n of lines
 **/
void zpop(stack_t **stack, unsigned int line_number)
{
	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(*stack)->next)
	{
		free(*stack);
		(*stack) = NULL;
		return;
	}
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}



/**
 * zadd - add func
 * @stack: pointer
 * @line_number: n of lines
 **/
void zadd(stack_t **stack, unsigned int line_number)
{
	int suma = 0;

	if (!(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	suma = (*stack)->n + (*stack)->next->n;
	(*stack)->next->n = suma;
	zpop(stack, line_number);
}

/**
 * zpint - pint func
 * @stack: pointer
 * @line_number: n of lines
 **/
void zpint(stack_t **stack, unsigned int line_number)
{
	const stack_t *aux;
	unsigned int len_stack = 0;

	aux = *stack;

	while (aux != NULL)
	{
		aux = aux->next;
		len_stack++;
	}

	if (*stack == NULL || len_stack < 1)
	{
		fprintf(stderr, "L%u: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * zfree - free all
 * @stack: pointer
 **/
void zfree(stack_t **stack)
{
	stack_t *tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

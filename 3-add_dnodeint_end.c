#include "monty.h"

/**
 * add_dnodeint_end - adds a new node at the end
 * @head: pointer to pointer
 * @n: content
 * @line_number: n of line
 * Return: pointer
 **/
void add_dnodeint_end(stack_t **head, const int n, unsigned int line_number)
{
	stack_t *new, *end;

	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "L%u: usage: can't malloc\n", line_number);
		exit(EXIT_FAILURE);
	}
	new->n = n;
	end = *head;
	if (*head)
	{
		while (end->next)
			end = end->next;
		end->next = new;
	}
	else
		*head = new;
	new->prev = end;
}

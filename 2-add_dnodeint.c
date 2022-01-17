#include "monty.h"

/**
 * add_dnodeint - add a new node at the beggining
 * @head: pointer to pointer
 * @n: content
 * @line_number: n of line
 * Return: end program
 **/
void add_dnodeint(stack_t **head, const int n, unsigned int line_number)
{
	stack_t *upd = malloc(sizeof(stack_t));

	if (!upd)
	{
		fprintf(stderr, "L%u: usage: can't malloc\n", line_number);
		exit(EXIT_FAILURE);
	}
	upd->n = n;
	upd->prev = NULL;
	upd->next = NULL;

	if (!(*head))
	{
		*head = upd;
	}
	upd->next = *head;
	(*head)->prev = upd;
	*head = upd;
}

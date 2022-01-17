#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void part2(char *zbuffer, instruction_t (*comms)[], unsigned int line_number, stack_t **stack);
void zpint(stack_t **stack, unsigned int line_number);
void zpop(stack_t **stack, unsigned int line_number);
void zswap(stack_t **stack, unsigned int line_number);
void zadd(stack_t **stack, unsigned int line_number);
void zfree(stack_t **stack);
void zpall(stack_t **stack, unsigned int line_number);
void zpush(stack_t **stack, unsigned int line_number);
void add_dnodeint(stack_t **head, const int n, unsigned int line_number);
void add_dnodeint_end(stack_t **head, const int n, unsigned int line_number);

#endif

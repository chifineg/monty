#include "monty.h"
#include <string.h>

void free_stack(stack_t **stack);
int init_stack(stack_t **stack);
int check_mode(stack_t *stack);

/**
 * free_stack - Frees a stack_t stack.
 * @stack: points to the top (stack) or
 *         bottom (queue) of a stack_t.
 */
void free_stack(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

/**
 * init_stack - function to initialize a stack_t stack with beginning
 *              stack and ending queue nodes.
 * @stack: points to unitialized stack_t stack.
 *
 * Return: EXIT_FAILURE when error.
 *         Otherwise - EXIT_SUCCESS.
 */
int init_stack(stack_t **stack)
{
	stack_t *c;

	c = malloc(sizeof(stack_t));
	if (c == NULL)
		return (malloc_error());

	c->n = STACK;
	c->prev = NULL;
	c->next = NULL;

	*stack = c;

	return (EXIT_SUCCESS);
}

/**
 * check_mode - function to check if a stack_t linked list
 * 	is in stack or queue mode.
 * @stack: points to the top (stack) or bottom (queue)
 *         of a stack_t linked list.
 *
 * Return: when stack_t is in stack mode - STACK (0).
 *         when stack_t is in queue mode - QUEUE (1).
 *         Otherwise - 2.
 */
int check_mode(stack_t *stack)
{
	if (stack->n == STACK)
		return (STACK);
	else if (stack->n == QUEUE)
		return (QUEUE);
	return (2);
}

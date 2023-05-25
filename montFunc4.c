#include "monty.h"

void monty_rotl(stack_t **stack, unsigned int line_number);
void monty_rotr(stack_t **stack, unsigned int line_number);
void monty_stack(stack_t **stack, unsigned int line_number);
void monty_queue(stack_t **stack, unsigned int line_number);

/**
 * monty_rotl - function to rotate up value of a stack_t linked list down.
 * @stack: points to the top mode node of a stack_t linked list.
 * @line_number: present working line number of a Monty bytecodes file.
 */
void monty_rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *up, *down;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	up = (*stack)->next;
	down = (*stack)->next;
	while (down->next != NULL)
		down = down->next;

	up->next->prev = *stack;
	(*stack)->next = up->next;
	down->next = up;
	up->next = NULL;
	up->prev = down;

	(void)line_number;
}

/**
 * monty_rotr - function to rotate the down value of a stack_t linked list up.
 * @stack: points to the top mode node of a stack_t linked list.
 * @line_number: present working line number of a Monty bytecodes file.
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *up, *down;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	up = (*stack)->next;
	down = (*stack)->next;
	while (down->next != NULL)
		down = down->next;

	down->prev->next = NULL;
	(*stack)->next = down;
	down->prev = *stack;
	down->next = up;
	up->prev = down;

	(void)line_number;
}

/**
 * monty_stack - function to change a queue to a stack.
 * @stack: points to the top mode node of a stack_t linked list.
 * @line_number: present working line number of a Monty bytecodes file.
 */
void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - function to change a stack to a queue.
 * @stack: points to the top mode node of a stack_t linked list.
 * @line_number: present working line number of a Monty bytecodes file.
 */
void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}

#include "monty.h"

void monty_push(stack_t **stack, unsigned int line_number);
void monty_pall(stack_t **stack, unsigned int line_number);
void monty_pint(stack_t **stack, unsigned int line_number);
void monty_pop(stack_t **stack, unsigned int line_number);
void monty_swap(stack_t **stack, unsigned int line_number);

/**
 * monty_push - value to a stack_t linked list is pushed.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: current line number of a Monty bytecodes file.
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmep, *new;
	int x;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		set_op_tok_error(malloc_error());
		return;
	}

	if (op_toks[1] == NULL)
	{
		set_op_tok_error(no_int_error(line_number));
		return;
	}

	for (x = 0; op_toks[1][x]; x++)
	{
		if (op_toks[1][x] == '-' && x == 0)
			continue;
		if (op_toks[1][x] < '0' || op_toks[1][x] > '9')
		{
			set_op_tok_error(no_int_error(line_number));
			return;
		}
	}
	new->n = atoi(op_toks[1]);

	if (check_mode(*stack) == STACK)
	{
		tmep = (*stack)->next;
		new->prev = *stack;
		new->next = tmep;
		if (tmep)
			tmep->prev = new;
		(*stack)->next = new;
	}
	else
	{
		tmep = *stack;
		while (tmep->next)
			tmep = tmep->next;
		new->prev = tmep;
		new->next = NULL;
		tmep->next = new;
	}
}

/**
 * monty_pall - values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: current line number of a Monty bytecodes file.
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmep = (*stack)->next;

	while (tmep)
	{
		printf("%d\n", tmep->n);
		tmep = tmep->next;
	}
	(void)line_number;
}

/**
 * monty_pint - top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: current line number of a Monty bytecodes file.
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pint_error(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}


/**
 * monty_pop - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: current line number of a Monty bytecodes file.
 */
void monty_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *next = NULL;

	if ((*stack)->next == NULL)
	{
		set_op_tok_error(pop_error(line_number));
		return;
	}

	next = (*stack)->next->next;
	free((*stack)->next);
	if (next)
		next->prev = *stack;
	(*stack)->next = next;
}

/**
 * monty_swap - topmost two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: current line number of a Monty bytecodes file.
 */
void monty_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmep;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "swap"));
		return;
	}

	tmep = (*stack)->next->next;
	(*stack)->next->next = tmep->next;
	(*stack)->next->prev = tmep;
	if (tmep->next)
		tmep->next->prev = (*stack)->next;
	tmep->next = (*stack)->next;
	tmep->prev = *stack;
	(*stack)->next = tmep;
}

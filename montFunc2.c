#include "monty.h"

void monty_add(stack_t **stack, unsigned int line_number);
void monty_sub(stack_t **stack, unsigned int line_number);
void monty_div(stack_t **stack, unsigned int line_number);
void monty_mul(stack_t **stack, unsigned int line_number);
void monty_mod(stack_t **stack, unsigned int line_number);

/**
 * monty_add - function to add top two values of a stack_t linked list.
 * @stack: points to the top mode node of a stack_t linked list.
 * @line_number: present working line number of a Monty bytecodes file.
 *
 * Description: result stored in the second value node
 *              from the top and the top value is deleted.
 */
void monty_add(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_sub - minus second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: points to the top mode node of a stack_t linked list.
 * @line_number: present working line number of a Monty bytecodes file.
 *
 * Description: result stored in the second value node
 *              from the top and the top value is deleted.
 */
void monty_sub(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_div - function to divide second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: points to the top mode node of a stack_t linked list.
 * @line_number: present working line number of a Monty bytecodes file.
 *
 * Description: result stored in the second value node
 *              from the top and the top value is deleted.
 */
void monty_div(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mul - function to multiply second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: points to the top mode node of a stack_t linked list.
 * @line_number: present working line number of a Monty bytecodes file.
 *
 * Description: result stored in the second value node
 *              from the top and the top value is deleted.
 */
void monty_mul(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_pop(stack, line_number);
}

/**
 * monty_mod - funtion to calculate modulus of the second value from the
 *             top of a stack_t linked list by the top value.
 * @stack: points to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: result stored in the second value node
 *              from the top and the top value is deleted.
 */
void monty_mod(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_op_tok_error(short_stack_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_op_tok_error(div_error(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_pop(stack, line_number);
}

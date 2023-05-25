#include "monty.h"

/**
 * set_op_tok_error - function to set last
 * 	element of op_toks to be an error code.
 * @error_code: Int value to store as a string in op_toks.
 */
void set_op_tok_error(int error_code)
{
	int toks_len = 0, x = 0;
	char *exit_str = NULL;
	char **new_toks = NULL;

	toks_len = token_arr_len();
	new_toks = malloc(sizeof(char *) * (toks_len + 2));
	if (!op_toks)
	{
		malloc_error();
		return;
	}
	while (x < toks_len)
	{
		new_toks[x] = op_toks[x];
		x++;
	}
	exit_str = get_int(error_code);
	if (!exit_str)
	{
		free(new_toks);
		malloc_error();
		return;
	}
	new_toks[x++] = exit_str;
	new_toks[x] = NULL;
	free(op_toks);
	op_toks = new_toks;
}

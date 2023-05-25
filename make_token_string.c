#include <stdlib.h>

char **strtow(char *str, char *delims);
int is_delim(char ch, char *delims);
int get_word_length(char *str, char *delims);
int get_word_count(char *str, char *delims);
char *get_next_word(char *str, char *delims);

/**
 * strtow - seperates the words in a string
 *
 * @str: seperate this string into words
 * @delims: used to delimit words
 *
 * Return: Array of pointers to each word
 */

char **strtow(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordLen, n, x = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = get_word_count(str, delims);


	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (x < wc)
	{
		wordLen = get_word_length(str, delims);
		if (is_delim(*str, delims))
		{
			str = get_next_word(str, delims);
		}
		words[x] = malloc((wordLen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (x >= 0)
			{
				x--;
				free(words[x]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[x][n] = *(str + n);
			n++;
		}
		words[x][n] = '\0';
		str = get_next_word(str, delims);
		x++;
	}
	words[x] = NULL;
	return (words);
}

/**
 * is_delim -  delimitor char in stream
 *
 * @ch: character in stream
 *
 * @delims: null terminated array of delimitors
 *
 * Return: 1 (success) 0 (failure)
 */

int is_delim(char ch, char *delims)
{
	int x = 0;

	while (delims[x])
	{
		if (delims[x] == ch)
			return (1);
		x++;
	}
	return (0);
}

/**
 * get_word_length - word length of cur word in str
 *
 * @str: word length from current word
 * @delims: used to delimit words
 *
 * Return: length of current word
 */

int get_word_length(char *str, char *delims)
{
	int wLen = 0, pending = 1, x = 0;

	while (*(str + x))
	{
		if (is_delim(str[x], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && is_delim(str[x], delims))
			break;
		x++;
	}
	return (wLen);
}

/**
 * get_word_count - word count of a string
 *
 * @str: string to get word count from
 * @delims: use to delimit words
 *
 * Return: the word count of the string
 */

int get_word_count(char *str, char *delims)
{
	int wc = 0, pending = 1, x = 0;

	while (*(str + x))
	{
		if (is_delim(str[x], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		x++;
	}
	return (wc);
}

/**
 * get_next_word - next word in a string
 *
 * @str: string to get next word from
 * @delims: use to delimit words
 *
 * Return: points to first char of next word
 */

char *get_next_word(char *str, char *delims)
{
	int pending = 0;
	int x = 0;

	while (*(str + x))
	{
		if (is_delim(str[x], delims))
			pending = 1;
		else if (pending)
			break;
		x++;
	}
	return (str + x);
}

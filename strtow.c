#include "monty.h"
#include "lists.h"

/**
 * word_counting - count string numbers
 * @s: valuated string
 * Return: words number
 */
int word_counting(char *s)
{
	int flag, c, w;
	flag = 0;
	w = 0;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}

	return (w);
}
/**
 * **stringtow - cut string to words
 * @str: the string to be splited
 * Return: pointer to an array of strings in success
 * or NULL in fail
 */
char **stringtow(char *str)
{
	char **matrix, *tmp;
	int i, k = 0, len = 0, words, c = 0, start, end;
	len = strlen(str);
	words = word_counting(str);
	if (words == 0)
		return (NULL);

	matrix = (char **) malloc(sizeof(char *) * (words + 1));
	if (matrix == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (isspace(str[i]) || str[i] == '\0' || str[i] == '\n')
		{
			if (c)
			{
				end = i;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				matrix[k] = tmp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	matrix[k] = NULL;

	return (matrix);
}

/**
 * all_freeing - make empty array string
 * @args: freeable array strings
 */
void all_freeing(char **args)
{
	int i;

	if (!args)
		return;

	for (i = 0; args[i]; i++)
		free(args[i]);

	free(args);
}

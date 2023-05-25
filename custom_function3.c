#include "main.h"

/**
 * exit_with - function that exit a string within
 * @c: character
 * @str: string
 * Return: boolean
 */
int exit_with(char c, char *str)
{
	if (*str == '\0')
		return (c == *str);
	return (c == *str ? 1 : exists_within(c, str + 1));
}
/**
 * _strtok - function that splits a string and returns an array
 * @str: string
 * @dlm: delimeters string
 * Return: tokens set
 */
char **_strtok(char *str, char *dlm)
{
	char **tokens;
	size_t j = 0, i, len = _strlen(str) + 1;
	int found = 1, k = 0;

	tokens = (char **)_calloc(len * sizeof(char *), sizeof(char));
	*tokens = (char *)_calloc(len, sizeof(char));
	if (!*tokens)
		free(tokens);
	for (i = 0; str[i]; i++)
	{
		if (exit_with(str[i], dlm))
		{
			if (!found)
			{
				tokens[k++][j] = '\0';
				tokens[k] = (char *)_calloc(len, sizeof(char));
				if (!tokens[k])
					_free(tokens);
			}
			found = 1;
			j = 0;
		}
		else
		{
			tokens[k][j++] = str[i];
			found = 0;
		}
	}
	if (found)
	{
		free(tokens[k]);
		tokens[k] = NULL;
	}
	else
		tokens[k][j] = '\0';
	return (tokens);
}
/**
 * sub_replacing - function taht replace two substring
 * @str: input string
 * @old_sub: old substring
 * @new_sub: input substring
 * Return: command decomposition
 */
void sub_replacing(char *str, char *old_sub, char *new_sub)
{
	char *ptr = NULL;
	size_t old_len = _strlen(old_sub);
	size_t new_len = _strlen(new_sub);
	size_t k = new_len, l = old_len;

	ptr = _strstr(str, old_sub);
	if (!ptr)
		return;
	do {
		ptr[k++] = ptr[l++];
	} while (ptr[l]);
	ptr[k] = '\0';
	_memcpy(ptr, new_sub, new_len);
	sub_replacing(ptr + new_len, old_sub, new_sub);
}

/**
 * _atoi - function that convert a string to an integer
 *
 *@str: string
 * Return: integer
 */

int _atoi(char *str)
{
	int i, x;
	unsigned int nbr;

	for (i = 0, nbr = 0, x = 1; str[i] != '\0'; i++)
	{
		if (str[i] == '-')
			x = -x;
		if (str[i] >= '0' && str[i] <= '9')
		{
			nbr = (nbr * 10) + (str[i] - '0');
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
				break;
		}
	}
	nbr *= x;
	return (nbr);
}

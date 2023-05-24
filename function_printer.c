#include "main.h"

/**
 * to_string - function that cast an integer to decimal
 * @nbr: input number
 * @i: integer
 * Return: length of string.
 */
int to_string(int i, unsigned int nbr)
{
	char dgt;

	if (nbr >= 10)
		return (to_string(i, nbr / 10) + to_string(i, nbr % 10));
	dgt = '0' + nbr;
	if (i == 1)
		return (write(STDOUT_FILENO, &dgt, 1));
	return (write(STDERR_FILENO, &dgt, 1));
}
/**
 * str_toprint - function print a string.
 * @str: a string
 * @i: an integer
 * Return: length of string.
 */
int str_toprint(int i, char *str)
{
	if (i == 1)
		return (write(STDOUT_FILENO, str, _strlen(str)));
	return (write(STDERR_FILENO, str, _strlen(str)));
}

#include "main.h"

/**
 * _getline - function that get string to read.
 * @l: string to read
 * Return: string length
 */
int _getline(char **l)
{
	int i;

	*l = _calloc(10240, sizeof(char));
	i = read(STDIN_FILENO, *l, 10240);
	(*l)[i] = '\0';
	return (i);
}

/**
 * _read - function that reads an input from a file
 * @l: line holder
 * @args: argument source
 * Return: integer
 */
int _read(char **l, char **args)
{
	ssize_t i;
	int r;

	r = open(args[1], O_RDONLY);
	if (r == -1)
	{
		error(args[0], args, NULL, 11);
		exit(EXIT_FAILURE);
	}
	*l = _calloc(10240, sizeof(char));
	i = read(r, *l, 10240);
	close(r);
	while (**l == ' ' || **l == '\t')
		(*l)++, i--;
	(*l)[i] = '\0';
	return (i);
}

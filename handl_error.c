#include "main.h"

/**
 * error2 - prints error msgs to stderr
 * @args: arguments
 * @path: path
 * @ie: index of the error
 */
void error2(char **args, char *path, int ie)
{
	char semicol = ';';

	if (ie == 5)
		_str_toprint(2, "usage: unsetenv VARIABLE VALUE");
	else if (ie == 6)
	{
		_str_toprint(2, "environment variable ");
		_str_toprint(2, args[1]);
		_str_toprint(2, " not found");
	}
	else if (ie == 7)
		_str_toprint(2, "Syntax error: \"&\" unexpected");
	else if (ie == 8)
		_str_toprint(2, "Syntax error: \"|\" unexpected");
	else if (ie == 9)
	{
		_str_toprint(2, "Syntax error: \"");
		write(STDERR_FILENO, &semicol, 1);
		write(STDERR_FILENO, &semicol, 1);
		_str_toprint(2, "\" unexpected");
	}
	else if (ie == 10)
	{
		_str_toprint(2, "alias: ");
		_str_toprint(2, path);
		_str_toprint(2, " not found");
	}
}

/**
 * error - prints error msgs to stderr
 * @name: name
 * @args: arguments
 * @path: path
 * @ie: index of the error
 * Return: value
 */
int error(char *name, char **args, char *path, int ie)
{
	static unsigned int i;

	if (!ie)
	{
		i++;
		return (0);
	}
	if (ie == 11)
	{
		_str_toprint(2, name);
		_str_toprint(2, ": 0: Can't open ");
		_str_toprint(2, args[1]);
		write(STDERR_FILENO, "\n", 1);
		return (EXIT_FAILURE);
	}
	_str_toprint(2, name);
	_str_toprint(2, ": ");
	to_string(2, i);
	_str_toprint(2, ": ");
	if (ie == 1)
	{
		_str_toprint(2, args[0]);
		_str_toprint(2, ": not found");
	}
	else if (ie == 2)
	{
		_str_toprint(2, "exit: Illegal number: ");
		_str_toprint(2, args[1]);
	}
	else if (ie == 3)
	{
		_str_toprint(2, "cd: can't cd to ");
		_str_toprint(2, path);
	}
	else if (ie == 4)
		_str_toprint(2, "usage: setenv VARIABLE VALUE");
	else
		error2(args, path, ie);
	write(STDERR_FILENO, "\n", 1);
	return (EXIT_FAILURE);
}

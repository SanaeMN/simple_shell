#include "main.h"

/**
 * echo - handle variables replacement.
 * @vars: variable
 * Return: success
 */
int echo(char **vars)
{
	int status;

	if (!_strcmp(vars[0], "echo") && vars[1])
	{
		if (!_strcmp(vars[1], "$$"))
		{
			to_string(1, getpid());
			write(STDOUT_FILENO, "\n", 1);
			return (1);
		}
		else if (!_strcmp(vars[1], "$?"))
		{
			waitpid(getpid() - 1, &status, 0);
			to_string(1, WEXITSTATUS(status));
			write(STDOUT_FILENO, "\n", 1);
			return (1);
		}
	}
	return (0);
}

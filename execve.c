#include "main.h"

/**
 * execute_cmd - function execute an command given
 * @array: array of argument
 * @name: name
 * @path: path
 * Return: success
 */
int execute_cmd(char **array, char *name, char *path)
{
	int i = 0, success = 1;
	char *env;

	(void) name;
	if (array)
	{
		i = echo(array);
		if (i == 0 && array[1] && array[1][0] == '$')
		{
			env = _getenv(array[1] + 1);
			if (env)
			{
				array[1] = malloc(sizeof(env));
				_strcpy(array[1], env);
			}
			else
			{
				write(STDOUT_FILENO, "\n", 1);
				return (1);
			}
		}
		if (i == 0)
		{
			if (execve(path, array, environ) == -1)
				success = 0;
		}
		_free(array);
	}
	return (success);
}

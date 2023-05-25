#include "main.h"

/**
 * _fork - function creates a new child process.
 * @name: command name
 * @array: arguments
 * Return: success
 */
int _fork(char *name, char **array)
{
	pid_t pid;
	int status, success = 1;
	char *path = NULL;

	path = valid_cmd(array[0], name, array);
	if (path != NULL)
	{
		pid = fork();
		if (pid == 0)
		{
			success = execmd(array, name, path);
			exit(0);
		}
		else
			waitpid(pid, &status, 0);
		free(path);
	}
	else
	{
		error(name, array, NULL, 1);
		success = 0;
	}
	return (success);
}

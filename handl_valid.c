#include "main.h"

/**
 * valid_cmd - function that check valid command.
 * @cmd: command
 * @name: name
 * @array: argument array
 * Return: string
 */
char *valid_cmd(char *cmd, char *name, char **array)
{
	int i;
	struct stat buffer;
	char *path, **path_array = NULL, *env;

	env = _getenv("PATH");
	if (!env)
	{
		if (!access(cmd, X_OK) && stat(cmd, &buffer) == 0)
			return (cmd);
		return (NULL);
	}
	else if (*env == '\0')
	{
		error(name, array, NULL, 1);
		exit(EXIT_FAILURE);
	}
	else
		path_array = _strtok(env, ":");
	for (i = 0; path_array[i]; i++)
	{
		if (!_strstr(cmd, "/"))
		{
			path = malloc(_strlen(path_array[i]) + _strlen(cmd) + 3);
			_strcpy(path, path_array[i]);
			_strcat(path, "/");
			_strcat(path, cmd);
		}
		else
			path = malloc(_strlen(cmd) + 2), _strcpy(path, cmd);
		if (!access(path, X_OK) && stat(path, &buffer) == 0)
		{
			_free(path_array);
			return (path);
		}
		free(path);
	}
	_free(path_array);
	return (NULL);
}

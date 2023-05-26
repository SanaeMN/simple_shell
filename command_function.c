#include "main.h"

/**
 * func_exit - function that exit
 * @ca: counter of arguments
 * @args: arguments
 * @name: program name
 * @alias: type struct
 * @index: index of argument
 * @split: split line
 * @l: line
 * Return: success
 */
int func_exit(int ca, char **args, char *name,
		alias_sh *alias, int *index, char **split, char *l)
{
	int i = 0;

	(void) alias;
	(void) index;
	while (ca > 1 && args[1][i])
	{
		if (args[1][i] < '0' || args[1][i] > '9')
		{
			error(name, args, NULL, 2);
			return (0);
		}
		i++;
	}
	if (ca > 1)
		i = _atoi(args[1]);
	_free(split);
	free(l);
	_free(args);
	exit(i);
	return (1);
}
/**
 * handle_direc - function that handles cd path.
 * @ac: counter of arguments
 * @args: arguments
 * @name: program name
 * @alias: type struct
 * @index: index of argument
 * @split: split line
 * @l: line
 * Return: success
 */
int handle_direc(int ac, char **args, char *name,
		alias_sh *alias, int *index, char **split, char *l)
{
	char *path, *tp;

	(void) alias;
	(void) index;
	(void) l;
	(void) split;
	path = ac == 1 || _strcmp(args[1], "~") == 0 ? _getenv("HOME") : args[1];
	if (chdir(path) < 0)
	{
		error(name, args, path, 3);
		return (0);
	}
	tp = _getenv("PWD");
	_strcpy(tp, path);
	if (ac == 1)
	{
		str_toprint(1, path);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}
/**
 * export - function that changes or adds an environment variable
 * @ac: counter of arguments
 * @args: arguments
 * @name: program name
 * @alias: type struct
 * @index: index of argument
 * @split: split line
 * @l: line
 * Return: success
 */
int export(int ac, char **args, char *name,
		alias_sh *alias, int *index, char **split, char *l)
{
	int i = 0;
	char *tp = NULL;

	(void) alias;
	(void) index;
	(void) split;
	(void) l;
	if (ac != 3)
	{
		error(name, args, NULL, 4);
		return (0);
	}
	else
	{
		tp = _getenv(args[1]);
		if (tp)
			_strcpy(tp, args[2]);
		else
		{
			while (environ[i])
				i++;
			environ[i] = _calloc(_strlen(args[1]) + _strlen(args[2]) + 3, 1);
			_strcat(environ[i], args[1]);
			_strcat(environ[i], "=");
			_strcat(environ[i], args[2]);
			environ[++i] = NULL;
		}
		return (1);
	}
}
/**
 * unsetenv - function that deletes the variable name from the environment
 * @ac: counter of arguments
 * @args: arguments
 * @name: program name
 * @alias: type struct
 * @index: index of argument
 * @split: split line
 * @l: line
 * Return: success
 */
int _unsetenv(int ac, char **args, char *name,
		alias_sh *alias, int *index, char **split, char *l)
{
	int i = 0;

	(void) alias;
	(void) index;
	(void) split;
	(void) l;
	if (ac != 2)
	{
		error(name, args, NULL, 5);
		return (0);
	}
	else if (_getenv(args[1]) == NULL)
	{
		error(name, args, NULL, 6);
		return (0);
	}
	else
	{
		while (environ[i])
		{
			if (_strncmp(environ[i], args[1], _strlen(args[1])) == 0)
			{
				free(environ[i]);
				break;
			}
			i++;
		}
		return (1);
	}
}
/**
 * env - funtion that handle and print the environment
 * @ac: counter of arguments
 * @args: arguments
 * @name: program name
 * @alias: type struct
 * @index: index of argument
 * @split: split line
 * @l: line
 * Return: success
 */
int env(int ac, char **args, char *name,
		alias_sh *alias, int *index, char **split, char *l)
{
	int i = 0;

	(void) ac;
	(void) args;
	(void) name;
	(void) split;
	(void) alias;
	(void) index;
	(void) l;
	while (environ[i])
	{
		str_toprint(1, environ[i]);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (1);
}

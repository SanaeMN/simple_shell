#include "main.h"

/**
 * _getenv - function that gets an environment variable.
 * @name: variable name
 * Return: string
 */
char *_getenv(char *name)
{
	int i;
	char *tp;

	for (i = 0; environ[i]; i++)
	{
		if (!_strncmp(name, environ[i], _strlen(name)))
		{
			tp = _strstr(environ[i], "=");
			tp++;
			return (tp);
		}
	}
	return (NULL);
}
/**
 * _handalias - function that handle an expression variable.
 * @alias: type struct
 * @name: variable name
 * @index: index of variable
 * Return: string
 */
int _handalias(alias_sh *alias, char *name, int index)
{
	int i = 0;

	while (i < index)
	{
		if (!_strcmp(name, alias[i].name))
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

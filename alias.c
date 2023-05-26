#include "main.h"

/**
 * _alias - works with aliases
 * @ac: arguments count
 * @args: arguments
 * @name: program name
 * @alias: type struct
 * @index: index of argument
 * @split: split line
 * @l: line
 * Return: success
 */
int _alias(int ac, char **args, char *name, alias_sh *alias, int *index,
		char **split, char *l)
{
	char **als;
	int i, j;

	(void) name;
	(void) split;
	(void) l;
	if (ac == 1)
	{
		for (i = 0; *index && i < *index; i++)
		{
			_str_toprint(1, alias[i].name), _str_toprint(1, "='");
			_str_toprint(1, alias[i].value), _str_toprint(1, "'\n");
		}
	}
	for (i = 1; i < ac; i++)
	{
		als = _strtok(args[i], "="), j = _handalias(alias, als[0], *index);
		if (!_strstr(args[i], "="))
		{
			if (j != -1)
			{
				_str_toprint(1, alias[j].name), _str_toprint(1, "='");
				_str_toprint(1, alias[j].value), _str_toprint(1, "'\n");
			}
			else
				error(name, args, args[i], 10);
		}
		else if (j != -1)
		{
			alias[j].value = malloc(_strlen(als[1]) + 1 + _strlen("''"));
			_strcpy(alias[j].value, als[1]);
		}
		else
		{
			alias[*index].name = malloc(_strlen(als[0]) + 1);
			alias[*index].value = malloc(_strlen(als[1]) + 1 + _strlen("''"));
			_strcpy(alias[*index].name, als[0]);
			_strcpy(alias[*index].value, als[1]), (*index)++;
		}
	}
	return (1);
}

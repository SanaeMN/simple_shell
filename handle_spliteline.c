#include "main.h"

/**
 * alias_check - function that check aliases code
 * @array: arguments array
 * @alias: alias array
 * @index: index of an integer
 * Return: none
 */
void alias_check(char ***array, alias_sh *alias, int index)
{
	int i = 0, n;

	while ((*array)[i])
	{
		n = _getalias(alias, (*array)[i], index);
		if (n != -1)
		{
			(*array)[i] = NULL;
			(*array)[i] = malloc(_strlen(alias[n].value) + 1);
			_strcpy((*array)[i], alias[n].value);
		}
		i++;
	}
}
/**
 * handle_and - function that handle addition
 * @l: input command line
 * @name: file name
 * @alias: alias array
 * @index: index of an integer
 * Return: integer
 */
int handle_and(char *l, char *name, alias_sh *alias, int *index)
{
	char **array, **l_split;
	int break_condition, ac, selector, i = 0;

	l_split = _strtok(l, "&\n");
	for (i = 0; l_split[i]; i++)
	{
		array = _strtok(l_split[i], " \t");
		if (args_count(array) == 0)
		{
			_free(array);
			_free(l_split);
			return (error(name, NULL, NULL, 7));
		}
		_free(array);
	}
	for (i = 0; l_split[i]; i++)
	{
		break_condition = 0;
		array = _strtok(l_split[i], " \t");
		if (_strcmp(array[0], "alias"))
			alias_check(&array, alias, *index);
		ac = args_count(array);
		selector = command_select(array[0], array, name, alias, index);
		if (ac > 0 && selector < 0)
			break_condition = 1 - _fork(name, array);
		else if (ac > 0)
			break_condition = 1 - selector;
		if (break_condition)
		{
			_free(array);
			break;
		}
		_free(array);
	}
	_free(l_split);
	return (break_condition ? 0 : EXIT_FAILURE);
}
/**
 * handle_or - function that handle or
 * @l: input command line
 * @name: file name
 * @alias: alias array
 * @index: index of an integer
 * Return: integer
 */
int handle_or(char *l, char *name, alias_sh *alias, int *index)
{
	char **array, **l_split;
	int break_condition, ac, selector, i = 0;

	l_split = _strtok(l, "|\n");
	for (i = 0; l_split[i]; i++)
	{
		array = _strtok(l_split[i], " \t");
		if (args_count(array) == 0)
		{
			_free(array);
			_free(l_split);
			return (error(name, NULL, NULL, 8));
		}
		_free(array);
	}
	i = 0;
	for (i = 0; l_split[i]; i++)
	{
		array = _strtok(l_split[i], " \t");
		if (_strcmp(array[0], "alias"))
			alias_check(&array, alias, *index);
		break_condition = 0;
		ac = args_count(array);
		selector = command_select(array[0], array, name, alias, index);
		if (ac > 0 && selector < 0)
			break_condition = _fork(name, array);
		else if (ac > 0)
			break_condition = selector;
		if (break_condition)
		{
			_free(array);
			break;
		}
		_free(array);
	}
	_free(l_split);
	return (break_condition ? 0 : EXIT_FAILURE);
}
/**
 * handle_semi_col - function that handle the semi column
 * @l: input command line
 * @name: file name
 * @alias: alias array
 * @index: index of an integer
 * Return: integer
 */
int handle_semi_col(char *l, char *name, alias_sh *alias, int *index)
{
	char **array, **l_split;
	int ac, i = 0, frk = 0;

	l_split = _strtok(line, ";\n");
	for (i = 0; l_split[i]; i++)
	{
		array = _strtok(l_split[i], " \t");
		if (args_count(array) == 0)
		{
			_free(array);
			_free(l_split);
			return (error(name, NULL, NULL, 9));
		}
		_free(array);
	}
	_free(l_split);
	l_split = _strtok(l, "@;\n");
	for (i = 0; l_split[i]; i++)
	{
		array = _strtok(l_split[i], " \t");
		if (_strstr(l, "alias"))
			alias_check(&array, alias, *index);
		ac = args_count(array);
		if (ac > 0 && command_select(array[0], array, name, alias, index) < 0)
			_fork(name, array);
		else if (!_strstr(line, "@") && ac == 0)
		{
			_free(l_split);
			_free(array);
			return (error(name, NULL, NULL, 9));
		}
		_free(array);
	}
	_free(l_split);
	return (frk ? EXIT_FAILURE : 0);
}
/**
 * split_line - read command line
 * @l: input command line
 * @name: file name
 * @alias: alias array
 * @index: index of an integer
 * Return: integer
 */
int split_line(char *l, char *name, alias_sh *alias, int *index)
{
	size_t old_len;
	size_t new_len;
	char *tp;

	while (*l == ' ' || *l == '\t')
		del(&l);
	old_len = _strlen(l);
	if (old_len == 1)
		return (0);
	tp = _strstr(l, "#");
	if (tp)
		*tp = '\0';
	sub_replacing(l, "&&", "&");
	new_len = _strlen(l);
	if (new_len < old_len)
	{
		sub_replacing(l, "&&", "&");
		if (_strlen(l) < new_len)
			return (error(name, NULL, NULL, 7));
		return (handle_and(l, name, alias, index));
	}
	sub_replacing(l, "||", "|");
	new_len = _strlen(l);
	if (new_len < old_len)
	{
		sub_replacing(l, "||", "|");
		if (_strlen(l) < new_len)
			return (error(name, NULL, NULL, 8));
		return (handle_or(l, name, alias, index));
	}
	if (_strstr(l, ";;"))
		return (error(name, NULL, NULL, 9));
	sub_replacing(l, "\n", "@");
	return (handle_semi_col(l, name, alias, index));
}

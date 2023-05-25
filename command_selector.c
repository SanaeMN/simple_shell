#include "main.h"

/**
 * command_select - function select the command using.
 * @cmd: command name
 * @args: arguments
 * @name: program name
 * @alias: struct
 * @index: index of selector
 * Return: success
 */
int command_select(const char *cmd, char **args,
		char *name, alias_sh *alias, int *index)
{
	command_exe exes[] = {
		{"exit", func_exit},
		{"cd", handle_direc},
		{"setenv", export},
		{"unsetenv", unsetenv},
		{"env", env},
		{"alias", _alias},
		{NULL, NULL}
	};
	int j = 0;

	while (exes[j].function_exe != NULL && _strcmp(cmd, exes[j].cmd) != 0)
		j++;
	if (exes[j].function_exe != NULL)
		return (exes[j].function_exe(args_count(args), args, name, alias, index));
	return (-1);
}

/**
 * args_count - function count arguments
 * @args: arguments
 * Return: argc
 */
int args_count(char **args)
{
	if (args == NULL || *args == NULL)
		return (0);
	return (1 + args_count(args + 1));
}

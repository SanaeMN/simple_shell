#include "main.h"

/**
 * main - function of a simple shell program project.
 * @ac: arguments count
 * @args: arguments set
 * Return: 0
 */
int main(int ac, char **args)
{
	alias_sh alias;
	int index = 0, r_val = 0;
	char *input = NULL, *name = args[0];

	(void) ac;
	alias.name = NULL;
	alias.value = NULL;
	while (1)
	{
		if (isatty(0) && ac == 1)
			write(STDOUT_FILENO, "$ ", 2);
		if (ac == 1 && _getline(&input) <= 0)
		{
			free(input);
			if (isatty(0))
				write(STDOUT_FILENO, "\n", 1);
			exit(r_val);
		}
		else if (ac != 1 && _read(&input, args) <= 0)
		{
			free(input);
			if (isatty(0))
				write(STDOUT_FILENO, "\n", 1);
			exit(r_val);
		}
		if (*input != '\0' && _strcmp(input, "\n"))
		{
			error(name, NULL, NULL, 0);
			r_val = split_line(input, name, &alias, &index);
		}
		free(input);
		if (ac != 1)
			return (0);
	}
}

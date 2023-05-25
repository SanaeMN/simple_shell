#include "main.h"

/**
 * _strpbrk - function searche a string for any of a set of bytes.
 *
 * @str: string
 * @act: characters to accept
 *
 * Return: nbr or 0
 */
char *_strpbrk(char *str, char *act)
{
	int i, j;

	if (*str == '\0' && *act == '\0')
		return (0);
	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; act[j] != '\0'; j++)
		{
			if (str[i] == act[j])
				break;
		}
		if (act[j] != '\0')
			break;
	}
	if (str[i] != '\0')
		return (&str[i]);
	return (0);
}
/**
 * _strcpy - function copie the string pointed to destination
 *
 *@src: source string
 *@dest: destination string
 * Return: string
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}
/**
 * _strcat - function concatenates two strings
 *
 *@src: first string
 *@dest: second string
 *
 *Return: dest string
 */

char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	dest[i] = ' ';
	for (j = 0; src[j] != '\0'; i++, j++)
		dest[i] = src[j];
	dest[i] = '\0';
	return (dest);
}

/**
 * del - deletes the first character of a string
 * @str: string
 */
void del(char **str)
{
	int i;

	for (i = 0; (*str)[i]; i++)
		(*str)[i] = (*str)[i + 1];
}

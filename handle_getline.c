#include "main.h"

/**
 * _strlen - function that give string length
 *
 *@str: string
 * Return: length of string
 */

size_t _strlen(char *str)
{
	if (!str || *str == '\0')
		return (0);
	return (1 + _strlen(str + 1));
}

/**
 * _strcmp - function that compares two strings
 *
 *@str1: first string
 *@str2: second string
 *
 *Return: integer
 */
int _strcmp(const char *str1, char *str2)
{
	for (; *str1 == *str2; str1++, str2++)
	{
		if (*str1 == '\0')
			return (0);
	}
	return (*str1 - *str2);
}
/**
 * _strncmp - function that compares n characters
 * @str1: first string
 * @str2: second string
 * @nbr: number
 * Return: integer
 */
int _strncmp(const char *str1, char *str2, int nbr)
{
	for (; nbr && *str1 == *str2; nbr--, str1++, str2++)
		;
	if (nbr)
		return (*str1 - *str2);
	return (0);
}
/**
 * _strstr - function that locates a substring.
 *
 * @hak: the string
 * @ndl: the string searching
 *
 * Return: location or NULL
 */

char *_strstr(char *hak, char *ndl)
{
	int i, j;

	if (*hak == '\0' && *ndl == '\0')
		return (NULL);
	for (i = 0; hak[i] != '\0'; i++)
	{
		for (j = 0; ndl[j] != '\0'; j++)
		{
			if (ndl[j] != hak[i + j])
				break;
		}
		if (ndl[j] == '\0')
			return (&hak[i]);
	}
	return (NULL);
}
/**
 * _memcpy - function that copies memory area.
 *
 * @dest: destination memory area
 * @src: source memory area
 * @nbr: bytes of the memory
 *
 * Return: dest
 */
char *_memcpy(char *dest, char *src, unsigned int nbr)
{
	unsigned int i = 0;

	while (i < nbr)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

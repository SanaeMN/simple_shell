#include "main.h"
/**
 * _free - function free the memory
 * @array: array allocate.
 */
void _free(char **array)
{
	int i = 0;

	if (array == NULL)
		return;
	while (array[i])
		free(array[i]);
		i++;
	free(array);
}
/**
 * _calloc - allocates memory for an array, using malloc.
 *
 * @nmb: number of members
 * @size: size of allocation
 *
 * Return: pointer or NULL
 */

void *_calloc(unsigned int nmb, unsigned int size)
{
	char *ptr;
	unsigned int i;

	if (nmb == 0 || size == 0)
		return (NULL);
	ptr = malloc(size * nmb);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < size * nmb)
		ptr[i] = 0;
		i++;
	return (ptr);
}

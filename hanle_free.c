#include "main.h"
/**
 * _free - function free the memory
 * @array: array allocate.
 */
void _free(char **array)
{
	int j = 0;

	if (array == NULL)
		return;
	for (j = 0; array[j]; j++)
	{
		free(array[j]);
	}
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
	unsigned int j;

	if (nmb == 0 || size == 0)
		return (NULL);
	ptr = malloc(size * nmb);
	if (ptr == NULL)
		return (NULL);

	for (j = 0; j < size * nmb; j++)
	{
		ptr[j] = 0;
	}
	return (ptr);
}

#include "main.h"

/**
 * _getenv - get enveronment value by its name
 * @name: string value
 * Return: a environment value
 */
char *_getenv(const char *name)
{
	size_t count = 0, indice = 0;

	if (name == NULL || *name == '\0')
		return (NULL);

	while (*(*(environ + count) + indice) != '\n' &&
			*(*(environ + count) + indice) != '=' &&
			*(name + indice) != '\0')
	{
		while (*(*(environ + count) + indice) == *(name + indice) &&
				*(*(environ + count) + indice) != '\0' &&
				*(name + indice) != '\0')
		{
			indice++;
			if (*(*(environ + count) + indice) == '=' &&
					*(name + indice) == '\0')
			{
				return ((*(environ + count) + (indice + 1)));
			}
		}
		indice = 0;
		count++;
	}

	return (NULL);
}

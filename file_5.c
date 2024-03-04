#include "shell.h"

/**
 * _strncpy - Copies a string up to n bytes from source to destination.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of bytes to be copied.
 *
 * Return: Pointer to the destination string.
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	for (i = 0; src[i] != '\0' && i < n - 1; i++)
		dest[i] = src[i];

	if (i < n)
	{
		for (j = i; j < n; j++)
			dest[j] = '\0';
	}

	return (s);
}

/**
 * _strncat - Concatenates a string up to n bytes from source to destination.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of bytes to be concatenated.
 *
 * Return: Pointer to the destination string.
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;
	char *s = dest;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';

	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

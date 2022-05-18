#include "main.h"

/**
 * is_in_str - checks whether given character is in a given string
 * @str: string
 * @c: character
 *
 * Return: 1 if c is in str. 0 Otherwise
 */
int is_in_str(const char *str, char c)
{
	if (str == NULL)
		return (0);

	while (*str)
	{
		if (*str == c)
			return (1);

		str++;
	}

	return (0);
}

/**
 * _atoi - converts a string to an integer
 * @str: string
 *
 * Return: integer equivalent. Otherwise -1
 */
int _atoi(char *str)
{
	int i, j, n, result;

	if (str == NULL)
		return (-1);

	n = _strlen(str);

	for (i = n - 1, j = 1, result = 0; i >= 0; i--, j *= 10)
	{
		if (result < 0 || str[i] > '9' || str[i] < '0')
			return (-1);

		result += (str[i] - '0') * j;
	}

	return (result % 256);
}

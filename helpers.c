#include "hshell.h"

/**
 * _putchar - prints a character to std out.
 * @c: the character to be printed.
 * Return: 1 if successful, 0 if not.
 */
int _putchar(char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}


/**
 * _puts - prints a string to stanard output
 * @s: the string to be printed.
 * Return: the number of characters printed.
 */

void _puts(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
}

/**
 * _atoi - converts a string to an integer
 * @s: string
 * Return: integer
 */

int _atoi(char *s)
{
	int i, val, sign;

	val = 0;
	sign = 1;

	for (i = 0; s[i] != '\0' && !(s[i] >= '0' && s[i] <= '9'); i++)
	{
		if (s[i] == '-')
			sign = sign * -1;
	}

	for (i = 0; s[i] != 0; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			val = val * 10 + sign * (s[i] - '0');
		if (val != 0 && !(s[i] >= '0' && s[i] <= '9'))
			return (val);
	}
	return (val);
}

/**
 * perror_string - prints a string to the standard error.
 * @s: the string to be printed.
 * Return: the number of char printed.
 */
int perror_string(char *s)
{
	int i, j;

	if (s == NULL)
		return (0);

	for (i = 0; s[i]; i++)
		j += write(STDERR_FILENO, &s[i], 1);

	return (j);
}

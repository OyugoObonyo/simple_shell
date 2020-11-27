#include "hshell.h"

/**
 * _strdup - copies and allocates space for a string
 * @s: the string to be copied.
 * Return: pointer to malloc'd space containing the copy of the string.
 */

char *_strdup(char *s)
{
	int i = 0;
	char *dup;

	dup = malloc(sizeof(char) * (_strlen(s) + 1));
	if (dup == NULL)
		return (NULL);
	for (i = 0; s[i]; i++)
		dup[i] = s[i];
	dup[i] = '\0';


	return (dup);
}

/**
 *_strcmp - compares pointers to two strings
 *@s1: A pointer to the first string to be compared
 *@s2: A pointer to the second string to be compared
 * Return: 1 if they are the same. 0 if they are not.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	if (!s1 || !s2)
		return (0);
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);

	return (0);
}

/**
 *_strlen-Prints the length of a string
 * @s:parameter
 *
 * Return:string length
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; ++i)
	{
	}
	return (i);
}

/**
 * _strtok - Tokenizes a string
 * @s: String
 * @delim: Delimitation agent
 * Return: pointer to the first Token
 */

char *_strtok(char *s, const char *delim)
{
	char *token;
	static int tok_s;
	static char *buftok;

	if (s != NULL)
	{
		buftok = s;
		tok_s = 0;
	}
	while (buftok[tok_s] == *delim && buftok[tok_s] != '\0')
		tok_s++;
	if (buftok[tok_s] != '\0')
		token = &buftok[tok_s];
	else
		return (NULL);
	while (buftok[tok_s] != '\0')
	{
		if (buftok[tok_s] == *delim)
		{
			buftok[tok_s] = '\0';
			tok_s++;
			return (token);
		}
		tok_s++;
	}
	return (token);
}

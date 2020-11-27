#include "hshell.h"

/**
 * check_stuff - Check for tabs, newlines, spaces.
 * @s: string to be checked
 */

void check_stuff(char *s)
{
	int i;
	int count;

	count = 0;
	if (s[0] == '#')
		s[0] = '\0';
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == '\t')
			s[i] = ' ';
		if (s[i] == '#' && i > 0 && s[i - 1] == ' ')
			s[i] = '\0';
		if (s[i] == '\n' && s[i + 1] == '\0')
			s[i] = '\0';
	}
	for (i = 0; s[i]; i++)
	{
		if (s[i] != ' ')
			count++;
	}
	if (count == 0)
		s[0] = '\0';
}

/**
 * var_parse - parses a "$var" into "var="
 * @var: the string to be parsed.
 * Return: malloc'd string. Caller must free.
 */

char *var_parse(char *var)
{
	int i, j;
	char *parsed_str;

	parsed_str = malloc(sizeof(char) * (_strlen(var) + 1));
	if (parsed_str == NULL)
		return (NULL);
	for (i = 1, j = 0; var[i]; i++, j++)
	{
		parsed_str[j] = var[i];
	}
	parsed_str[j] = '=';
	parsed_str[j + 1] = '\0';

	return (parsed_str);
}
/**
 * free_if_needed - frees a pointer if not null
 * @p: pointer
 */

void free_if_needed(char *p)
{
	if (p)
		free(p);
}

/**
 * free_array - frees the strings in a pointer array
 * @arr: the array of string pointers
 */

void free_array(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
}

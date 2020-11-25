#include "hshell.h"

/**
 * _ControlC - block signal of Ctrl + C
 * @s: signal to verify
 * Return: Nothing.
 */

void _ControlC(int s)
{
	(void)s;

	write(STDOUT_FILENO, "\nOjashell$ ", 11);
}

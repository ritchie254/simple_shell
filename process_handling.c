#include "alx.h"
/**
 * path_check - check if argumnt is already a path
 * @argm: entry argument
 * Return: arfuement on success else null
 */
char *path_check(char *argm)
{
	if (access(argm, X_OK) == 0)
		return (argm);
	return (NULL);
}

/**
 * execute_command - check if argumnt is already a path
 * @argm: entry argument
 * Return: argm (Success) NULL (Not found)
 */
char *execute_command(char *argm)
{
	char *path = NULL;
	link_t *head = NULL;
	char *buffer = NULL;

	path = _getenv("PATH");
	head = _link(path);
	buffer = _which(&head, argm);
	if (buffer != NULL)
	{
		free(path),
		release_list(head);
		return (buffer);
	}
	free(path);
	release_list(head);
	return (NULL);
}

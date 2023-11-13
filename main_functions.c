#include "alx.h"
/**
 * _getenv - find the environment variable
 * @var_name: variable
 * Return: NULL if fails or pointer to value
 */
char *_getenv(const char *var_name)
{
	int i;
	int j;
	char *a;
	char *cpy;/* copy */

	for (i = 0 ; environ[i] != NULL ; i++)
	{
		for (j = 0 ; var_name[j] == environ[i][j] && var_name[j] != '\0' ; j++)
		{
			if (var_name[j + 1] == '\0')
			{
				a = &environ[i][j + 2];
				cpy = malloc(sizeof(char) * str_length(a) + 1);

				if (!cpy)
					return (NULL);

				cpy = str_copy(cpy, a);
				return (cpy);
			}
		}
	}
	return (NULL);
}
/**
 * _getline - get line command line from the prompt
 * @bufline: command buffer line string.
 * @size: size of the command buffer lines.
 * @std: file stream where comes the command buffer line.
 * Return: number of bytes copied in the buffer.
 **/
ssize_t _getline(char **bufline, size_t *size, FILE *std)
{
	size_t count = 0;
	size_t alloc = 1024;
	char c;

	if (!bufline || !size || !std)
		return (-1);
	if (*bufline == NULL)
	{
		*bufline = malloc(alloc);
		if (!(*bufline))
			return (-1);
	}
	while ((c = get_char()) != EOF)
	{
		if (c == '\n')
		{
			count++;
			break;
		}
		count++;
		(*bufline)[count - 1] = c;
	}
	if (c == EOF)
	{
		return (-1);
	}
	(*bufline)[count] = '\0';
	return (count);
}
/**
* splitline - get line command
* @cl: command line
* Return: a pointer to string
**/
char **splitline(char *cl)
{
	char **ptr_string;
	int s = 100;/*size*/
	int pos = 0;/*position*/
	char *word;

	ptr_string = malloc(sizeof(char *) * s);
	if (ptr_string == NULL)
		exit(EXIT_FAILURE);
	word = _strtok(cl, " ");
	while (word != NULL)
	{
		ptr_string[pos++] = word;
		word = _strtok(NULL, " ");
	}
	ptr_string[pos] = NULL;
	return (ptr_string);
}
/**
 * execute_process - execute process function
 * @argm: arguments from command line
 * @argv: string
 * @counter: number of excution processes
 * Return: 0 (Success) -1 (Failed)
 **/
int execute_process(char **argm, char **argv, int counter)
{
	pid_t child_process;
	int status, status_output = 0;
	char *buffer = NULL, *command_path = NULL;

	command_path = path_check(argm[0]);
	if (command_path == NULL)
	{
		buffer = execute_command(argm[0]);
		if (buffer == NULL)
		{
			_printf("%s: %d: %s: not found\n", argv[0], counter, argm[0]);
			free(buffer);
			return (1);
		}
	}
	child_process = fork();
	if (child_process < 0)
		exit(errno);
	else if (child_process == 0)
	{
		if (command_path != NULL)
		{
			if (execve(command_path, argm, environ) == -1)
				exit(errno);
		}
		if (execve(buffer, argm, environ) == -1)
			exit(errno);
	}

	wait(&status);
	if (WIFEXITED(status))
		status_output = WEXITSTATUS(status);
	free(buffer);

	return (status_output);
}
/**
 * _which - search for  command in directories
 * @head: head
 * @argue: arguments
 * Return: path or nil
 **/
char *_which(link_t **head, char *argue)
{
	link_t *p = *head;
	char *buffer;

	if (argue[0] == '.' || argue[0] == '/')
	{
		if (access(argue, X_OK) == 0)
			return (argue);
	}

	while (p)
	{
		buffer = str_cat(p->dir, "/", argue);
		if (access(buffer, X_OK) == 0)
		{
			return (buffer);
		}
		free(buffer);
		p = p->next;
	}
	return (NULL);
}

#include "alx.h"
/**
 * str_length - find the length of a string
 * @s: entry string
 * Return: number of bytes
 **/
int str_length(char *s)
{
	int i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}
/**
 * str_cat - concatenate directories with the 1st position
 * @dir: directories
 * @slash: forward slash("/")
 * @arg: array of commands.
 * Return: str
 **/
char *str_cat(char *dir, char *slash, char *arg)
{
	char *str = NULL;
	int len_1, len_2, i, k;

	len_1 = str_length(dir);
	len_2 = str_length(arg);
	str = malloc(sizeof(char) * (len_1 + len_2 + 2));
	if (!str)
		return (NULL);
	for (i = 0; dir[i]; i++)
		str[i] = dir[i];
	str[i] = *slash;
	k = i + 1;
	for (i = 0; arg[i]; i++)
		str[k + i] = arg[i];
	str[k + i] = '\0';
	return (str);
}
/**
 * _strtok - tokenize a string
 * @string: string
 * @delimeter: delimeter to used to tokenize
 * Return: NULL if fails
 */
char *_strtok(char *string, char *delimeter)
{
	int i = 0, j = 0, a = 0;
	static char *tracker;

	if (!delimeter || (!string && !tracker))
		return (NULL);
	string == NULL ? string = tracker : string;
	for (; string[j] == ' ' ; j++)
	{
		if (string[j + 1] == '\0')
			return (NULL);
	}
	for (i = j ; string[i] != '\0' ; i++)
	{
		if (string[i] == *delimeter)
		{
			a = 1;
			break;
		}
	}
	for (; string[i] != '\0' ; i++)
		if (string[i] != delimeter[0])
			break;
		else if (string[i + 1] == '\0')
		{
			a = 0, string[i] = '\0';
			break;
		}
		else
			string[i] = '\0';
	if (a == 0)
	{
		tracker = NULL;
		return (string + j);
	}
	if (string + i)
		tracker = string + i;
	else
		tracker = NULL;
	return (string + j);
}
/**
 * *str_copy - copies the string pointed
 * @source: source string
 * @destination: destination string
 * Return: return a pointer char
 */
char *str_copy(char *destination, char *source)
{
	int a, b;

	for (a = 0; source[a] != '\0' ; a++)
	{
	}
	for (b = 0; b < a ; b++)
	{
		destination[b] = source[b];
	}
	for (; b <= a ; b++)
	{
		destination[b] = '\0';
	}
	return (destination);
}

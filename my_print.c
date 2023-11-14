#include "alx.h"
/**
* puts_char - writes the character to stdout
* @c: charcter
* Return: 1 (success)
* On error, -1 is returned, and errno is set appropriately.
*/

int puts_char(char c)
{
	return (write(1, &c, 1));
}
/**
* print_char - writes the character c to stdout.
* @a: The character to print
* Return: integer.
*/
int print_char(va_list a)
{
	puts_char(va_arg(a, int));
	return (1);
}
/**
* pint - print variable type integer.
* @a: arguments
* Return: Integer.
*/
int pint(va_list a)
{
	long int n, n_aux, d = 1, l_aux;
	int count = 0;

	n = va_arg(a, int);

	if (n < 0)
	{
		n_aux = -n;
		puts_char('-');
		count++;
	}
	else
		n_aux = n;
	l_aux = n_aux;
	while (n_aux > 9)
	{
		n_aux = n_aux / 10;
		d *= 10;
	}
	while (d > 0)
	{
		puts_char(((l_aux / d) % 10) + '0');
		count++;
		d /= 10;
	}
	return (count);
}
/**
* print_str - print variable type string.
* @a: number of arguments.
* Return: Integer.
*/
int print_str(va_list a)
{
	char *p;
	int b;

	p = va_arg(a, char *);
	if (p == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	for (b = 0 ; p[b] != '\0' ; b++)
	{
	puts_char(p[b]);
	}
	return (b);
}
/**
* _printf - print c,s,f,u,i,d
* @format: arguments
* Return: length of all characters
*/
int _printf(const char *format, ...)
{
form types[] = {
	{"c", print_char}, {"s", print_str}, {"d", pint}, {"i", pint}, {NULL, NULL}};
	va_list arguments;
	int pos = 0, length = 0, pos_form;

	va_start(arguments, format);
	if (!format || !format[pos])
		return (-1);
	for (; format[pos]; pos++)
	{
		if (format[pos] == '%')
		{
			if (format[pos + 1] == '\0')
				return (-1);
			if (format[pos + 1] == '%')
				puts_char(37), length++;
			else
			{
				for (pos_form = 0; types[pos_form].ch != NULL; pos_form++)
				{
					if (types[pos_form].ch[0] == format[pos + 1])
					{
						length += types[pos_form].func(arguments);
						break;
					}
				}
				if (types[pos_form].ch == NULL)
				{
					puts_char(format[pos]);
					puts_char(format[pos + 1]), length += 2;
				}
			}
			pos++;
		}
		else
			puts_char(format[pos]), length++;
	}
	va_end(arguments);
	return  (length);
}

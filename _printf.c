#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...);
int _strlen(const char *str);

/**
 * _printf - like printf
 * @format: the string input
 * @...: variable num of parameters
 *Return: num of characters
 */
void print_int(int n)
{
	if (n < 0) {
	_putchar('-');
	n = -n;
	}
	if (n/10)
	print_int(n/10);

	_putchar(n%10 + '0');
}
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j = 0;
	char char_format;
	char *str_format;
	
	va_start(args, format);
	
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] == '\\')
			if (format[i + 1] == 'n')
				_putchar('\n');
		if (format[i] == '%')
		{
			switch(format[i + 1])
			{
				case 'c':
					char_format = va_arg(args, int);
					_putchar(char_format);
					i++;
					break;
				case 's':
					str_format = va_arg(args, char *);
					for (j = 0; str_format[j] != '\0'; j++)
						_putchar(str_format[j]);
					i++;
					break;
				case '%':
					_putchar('%');
					break;
				case 'd':
					int_format = va_arg(args, int);
					print_int(int_format);
					i++;
					break;
				case 'i':
					int_format = va_arg(args, int);
					print_int(int_format);
					i++;
					break;
			}
		}		
		
		else
			_putchar(format[i]);
		
		i++;
	}
	va_end(args);
	return _strlen(format);
}

/**
 * _strlen - counts num of char
 * @str: format string
 * Return: nums of chars
 */

int _strlen(const char *str)
{
	int i, count = 0;
	
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '%' || str[i] == '\\')
		{
			count++;
			i++;
		}
		else
			count++;
	}
	return (count);
}

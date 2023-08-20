#include <unistd.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...);
int _strlen(const char *str);
int _putchar(char c);

/**
 * _putchar - prints characters
 * @c: char to be printed
 * Return: always 0
 */
int _putchar(char c)
{
        write(1, &c, 1);
        return (0);
}

/**
 * _printf - like printf
 * @format: the string input
 * @...: variable num of parameters
 *Return: num of characters
 */

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j = 0;
	char char_format;
	char *str_format;
	
	va_start(args, format);
	
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
	return (count);
}

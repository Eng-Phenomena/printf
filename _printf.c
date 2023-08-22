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
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j = 0;
	char char_format;
	char *str_format;
	int int_format, sum = _strlen(format);

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
			if (format[i + 1] == 'c')
			{
				char_format = va_arg(args, int);
				_putchar(char_format);
				i++;
			}
			else if (format[i + 1] == 's')
			{
				str_format = va_arg(args, char *);
				if (str_format == NULL)
					str_format = "(null)";
				for (j = 0; str_format[j] != '\0'; j++)
					sum += _putchar(str_format[j]);
				i++;
				sum--;
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				int_format = va_arg(args, int);
				sum += print_int(int_format);
				sum--;
				i++;
			}
			else if (format[i + 1] == 'b')
			{
				int_format = va_arg(args, int);
				if (int_format < 0)
					int_format = -int_format;
				sum += print_bin(int_format);
				i++;
			}
			else if (format[i + 1] == '%')
			{
				_putchar('%');
				i++;
			}
			else
			{
				if (format[i + 1] != '\0')
				{
					_putchar('%');
					_putchar(format[i + 1]);
					i++;
				}
			}
		}		
		
		else
			_putchar(format[i]);
		
		i++;
	}
	va_end(args);
	return (sum);
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

/**
 * print_int - prints integers
 * @n: num
 * Return: len of num
 */

int print_int(int n)
{
	int count = 0;

	if (n < 0)
		count++;
	count += len_num(n);

	if (n == MAX)
	{
		_putchar('-');
		_putchar('2');
		print_int(147483648);
	}
	else if (n < 0)
	{
	       	_putchar('-');
		n = -n;
	}

	if (n >= 10)
	{
		print_int(n / 10);
		print_int(n % 10);
	}

	else if (n < 10)
		_putchar(n + '0');

	return (count);
}

/**
 * len_num - num lenght
 * @n: num
 * Return: len
 */

int len_num(int n)
{
	if(n == 0)
		return(0);
	return (1 + len_num(n / 10));
}

/**
 * print_bin - prints an Unsigned int as a binary
 * @n: argument
 * Return: Pow
 */
int print_bin(int n)
{
	int pow = 0;
	int base = 1, i;

	for (i = 0; (n - base) >= 0; i++)
	{
		pow++;
		base *= 2;
	}
	base = base / 2;

	for (i = 0; i < pow; i++)
	{
		if (n - base >= 0)
		{
			n = n - base;
			_putchar('1');
		}
		else
		{
			_putchar('0');
		}
		base /= 2;
	}
	return (pow);
}

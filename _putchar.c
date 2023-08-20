#include <unistd.h>
/**
 * _putchar - prints characters
 * @c: char to be printed
 * Return: always 0
 */
int _putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

#include <unistd.h>
#include "main.h"
/**
 * _putchar - prints characters
 * @c: char to be printed
 * Return: always 1
 */
int _putchar(const char c)
{
        write(1, &c, 1);
        return (1);
}

#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define MAX -2147483648

int _printf(const char *format, ...);
int _strlen(const char *str);
int _putchar(const char c);
int print_int(int n);
int len_num(int n);

#endif

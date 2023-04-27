#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_char - prints a character
 * @c: the character to print
 *
 * Return: 1 (the number of characters printed)
 */
int print_char(char c)
{
return (write(1, &c, 1));
}

/**
 * print_string - prints a string
 * @str: the string to print
 *
 * Return: the number of characters printed
 */
int print_string(char *str)
{
int len;

if (str == NULL)
str = "(null)";
len = strlen(str);
return (write(1, str, len));
}

/**
 * print_integer - prints an integer
 * @n: the integer to print
 *
 * Return: the number of characters printed
 */
int print_integer(int n)
{
int len = 0;
unsigned int abs_val;

if (n < 0)
{
len += print_char('-');
abs_val = -n;
}
else
abs_val = n;

if (abs_val > 9)
len += print_integer(abs_val / 10);
len += print_char(abs_val % 10 + '0');
return (len);
}

/**
 * _printf - custom printf function
 * @format: the format string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
int count = 0;
va_list args;

if (format == NULL)
return (-1);
if (*format == '%' && *(format + 1) == '\0')
return (-1);
va_start(args, format);
while (*format != '\0')
{
if (*format == '%')
{
format++;
if (*format == '\0')
{
count += write(1, "%", 1);
return (-1);
}
else if (*format == '%')
count += write(1, "%", 1);
else if (*format == 'c')
count += print_char(va_arg(args, int));
else if (*format == 's')
count += print_string(va_arg(args, char *));
else if (*format == 'd'  || *format= 'i' )
count += print_integer(va_arg(args, int));
else
count += write(1, "%", 1) + write(1, format, 1);
}
else
count += write(1, format, 1);
format++;
}
va_end(args);
return (count);
}

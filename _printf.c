#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - recreates the printf function
 * @format: string with format specifier
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
int count = 0;
va_list args;
char c;

va_start(args, format);
if (format == NULL)
return (-1);
while (*format)
{
if (*format == '%')
{
format++;
if (*format == '\0')
{
count += write(1, "%", 1);
return (-1);
}
if (*format == '%')
{
count += write(1, "%", 1);
format++;
continue;
}
switch (*format)
{
case 'c':
{
c = (char)va_arg(args, int);
if (c == '\0')
count += write(1, " ", 1);
else
count += write(1, &c, 1);
break;
}
case 's':
{
char *str = va_arg(args, char *);
if (str == NULL)
count += write(1, "(null)", 6);
else
count += write(1, str, strlen(str));
}
break;
case '%':
count += write(1, "%", 1);
break;
default:
count += write(1, "%", 1) + write(1, format, 1);
break;
}
}
else
count += write(1, format, 1);
format++;
}
va_end(args);
return (count);
}

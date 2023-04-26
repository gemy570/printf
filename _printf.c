#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <stddef.h>
#include <unistd.h>
#include <limits.h>
/**
 * _printf - recreates the printf function
 * @format: string with format specifier
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
int count = 0;
va_list args;
va_start(args, format);

while (*format) 
{
if (*format == '%') 
{
format++;
switch (*format)
{
case 'c':
{
char c = (char)va_arg(args, int);
write(1, &c, 1);
count++;
break;
}
case 's':
{
char *s = va_arg(args, char *);
int len = 0;
while (s[len])
len++;
write(1, s, len);
count += len;
break;
}
case '%':
{
write(1, "%", 1);
count++;
break;
}
default:
{
write(1, "%", 1);
write(1, format, 1);
count += 2;
break;
}
}
}
else
{
write(1, format, 1);
count++;
}
format++;
}
	va_end(args);

	return (count);
}

#include <stdarg.h>
#include <unistd.h>
#include <string.h>
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
count += write(1, &c, 1);
break;
}
case 's':
count += write(1, va_arg(args, char *), strlen(va_arg(args, char *)));
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

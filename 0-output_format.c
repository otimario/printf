#include "main.h"
/**
 * _printf - function that produces output
 * @c: format identifier to return a single character
 * @s: format identifier to return string
 * @%: conversion specifier to return a format identifier
 * Return: always(0)
 */

int _printf(const char *format, ...)
{
	int alpha_char_print = 0;
	va_list args_list;

	if (format == NULL)
		return (-1);

	va_start(args_list, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			alpha_char_print++;
		}
		else
		{
			format++;

		if (*format == '\0')
			break;

		if (*format == '%')
		{
			write(1, format, 1);
			alpha_char_print++;
		}
		else if (*format == 'c')
		{
			char c = va_arg(args_list, int);

			write(1, &c, 1);
			alpha_char_print++;
		}
		else if (*format == 's')
		{
			char *str = va_arg(args_list, char*);
			int str_len = 0;

			while (str[str_len] != '\0')
				str_len++;

			write(1, str, str_len);
			alpha_char_print += str_len;
		}
		}

	format++;
	}

	va_end(args_list);

	return (alpha_char_print);
}

int main()
{
	return (0);
}

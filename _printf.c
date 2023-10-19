#include "main.h"
#include <limits.h>
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: format string containing the characters and the specifiers
 * Description: this function will call my mb_get_print() function that will
 * determine which printing function to call depending on the conversion
 * specifiers contained into fmt
 * Return: The lenght of the string format.
 */
int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flags_t *);
	const char *p;
	va_list mb_args;
	flags_t flags = {0, 0, 0};

	register int mb_str_count = 0;

	va_start(mb_args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				mb_str_count += _putchar('%');
				continue;
			}
			while (mb_get_flag(*p, &flags))
				p++;
			pfunc = mb_get_print(*p);
			mb_str_count += (pfunc)
				? pfunc(mb_args, &flags)
				: _printf("%%%c", *p);
		} else
			mb_str_count += _putchar(*p);
	}
	_putchar(-1);
	va_end(mb_args);
	return (mb_str_count);

}


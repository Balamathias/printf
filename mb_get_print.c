#include "main.h"

/**
 * mb_get_print - selects the right printing function
 * depending on the conversion specifier passed to _printf
 * @s: character that holds the conversion specifier
 * Description: the function loops through the structs array
 * func_arr[] to find a match between the specifier passed to _printf
 * and the first element of the struct, and then the approriate
 * printing function
 * Return: a pointer to the matching printing function
 */
int (*mb_get_print(char s))(va_list, flags_t *)
{
	ph func_arr[] = {
		{'i', mb_print_int},
		{'s', mb_print_string},
		{'c', mb_print_char},
		{'d', mb_print_int},
		{'u', mb_print_unsigned},
		{'x', mb_print_hex},
		{'X', mb_print_hex_big},
		{'b', mb_print_binary},
		{'o', mb_print_octal},
		{'R', mb_print_rot13},
		{'r', mb_print_rev},
		{'S', mb_print_bigS},
		{'p', mb_print_address},
		{'%', mb_print_percent}
		};
	int flags = 14;

	register int i;

	for (i = 0; i < flags; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}

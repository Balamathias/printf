#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct containing flags to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flags_t;

/**
 * struct printHandler - struct to choose the right function depending
 * on the format specifier passed to _printf()
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printHandler
{
	char c;
	int (*f)(va_list ap, flags_t *f);
} ph;

/*mb_ print_nums */
int mb_print_int(va_list l, flags_t *f);
void mb_print_number(int n);
int mb_print_unsigned(va_list l, flags_t *f);
int count_digit(int i);

/* mb_print_bases */
int mb_print_hex(va_list l, flags_t *f);
int mb_print_hex_big(va_list l, flags_t *f);
int mb_print_binary(va_list l, flags_t *f);
int mb_print_octal(va_list l, flags_t *f);

/* mb_converter */
char *mb_convert(unsigned long int num, int base, int lowercase);

/* _printf */
int _printf(const char *format, ...);

/* mb_get_print */
int (*mb_get_print(char s))(va_list, flags_t *);

/* mb_get_flag */
int mb_get_flag(char s, flags_t *f);

/* mb_print_alpha */
int mb_print_string(va_list l, flags_t *f);
int mb_print_char(va_list l, flags_t *f);

/* write_funcs */
int _putchar(char c);
int _puts(char *str);

/* mb_print_custom */
int mb_print_rot13(va_list l, flags_t *f);
int mb_print_rev(va_list l, flags_t *f);
int mb_print_bigS(va_list l, flags_t *f);

/* mb_print_address */
int mb_print_address(va_list l, flags_t *f);

/* mb_print_percent */
int mb_print_percent(va_list l, flags_t *f);

#endif

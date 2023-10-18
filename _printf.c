#include "main.h"
#include <stdio.h>

/**
* _printf - prints a string
* @format: the format string
* Return: the number of characters printed
*/
int _printf(const char *format, ...) {
    va_list list_of_args;
    va_start(list_of_args, format);

    int total_char_to_print = 0;
    int stdout_fd = 1; 

    while (*format != '\0') {
        if (*format != '%') {
            char character = *format;
            if (write(stdout_fd, &character, 1) == -1) {
            }
            total_char_to_print++;
        } else {
            
            switch (*++format) {
            case 'd':
                {
                    int num = va_arg(list_of_args, int);
                    int num_len = snprintf(NULL, 0, "%d", num);
                    char num_str[num_len + 1];
                    snprintf(num_str, num_len + 1, "%d", num);
                    if (write(stdout_fd, num_str, num_len) == -1) {
                    }
                    total_char_to_print += num_len;
                }
                break;
            case 'i':
                {
                    int num = va_arg(list_of_args, int);
                    int num_len = snprintf(NULL, 0, "%i", num);
                    char num_str[num_len + 1];
                    snprintf(num_str, num_len + 1, "%i", num);
                    if (write(stdout_fd, num_str, num_len) == -1) {
                    }
                    total_char_to_print += num_len;
                }
                break;
            case 'c':
                {
                    char character = (char)va_arg(list_of_args, int);
                    if (write(stdout_fd, &character, 1) == -1) {
                    }
                    total_char_to_print++;
                }
                break;
            case 's':
                {
                    char *str = va_arg(list_of_args, char *);
                    int str_len = strlen(str);
                    if (write(stdout_fd, str, str_len) == -1) {
                    }
                    total_char_to_print += str_len;
                }
                break;
            case 'f':
                {
                    double num = va_arg(list_of_args, double);
                    int num_len = snprintf(NULL, 0, "%f", num);
                    char num_str[num_len + 1];
                    snprintf(num_str, num_len + 1, "%f", num);
                    if (write(stdout_fd, num_str, num_len) == -1) {
                    }
                    total_char_to_print += num_len;
                }
                break;
            default:
                char percent = '%';
                char current_format = *format;
                if (write(stdout_fd, &percent, 1) == -1 ||     write(stdout_fd, &current_format, 1) == -1) {

                }
                total_char_to_print += 2;
                break;
            }
        }
        format++;
    }

    va_end(list_of_args);
    return total_char_to_print;
}

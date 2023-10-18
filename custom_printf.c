#include "main.h"

int _printf(const char *format, ...) {
    va_list list_of_args;
    va_start(list_of_args, format);

    int total_char_to_print = 0;

    while (*format != '\0') {
        if (*format != '%') {
            char character = *format;
            int result = write(1, &character, 1);
            if (result == -1) {
            }
            total_char_to_print++;
        } else {
            format++;
            if (*format == '\0') {
                break;
            }
            if (*format == '%') {
                int result = write(1, format, 1);
                if (result == -1) {
                }
                total_char_to_print++;
            } else if (*format == 'c') {
                int c = va_arg(list_of_args, int);
                int result = write(1, &c, sizeof(int));
                if (result == -1) {
                }
                total_char_to_print++;
            } else if (*format == 's') {
                char *str = va_arg(list_of_args, char *);
                int len = strlen(str);
                int result = write(1, str, len);
                if (result == -1) {
                }
                total_char_to_print += len;
            } else if (*format == 'i' || *format == 'd') {
                int num = va_arg(list_of_args, int);
                char buffer[12]; 
                // buffer to hold the integer as a string
                int idx = 0;

                if (num == 0) {
                    buffer[idx++] = '0';
                } else {
                    if (num < 0) {
                        buffer[idx++] = '-';
                        num = -num;
                    }
                    int temp = num;
                    while (temp > 0) {
                        int digit = temp % 10;
                        buffer[idx++] = digit + '0';
                        temp /= 10;
                    }
                    for (int i = 0, j = idx - 1; i < j; i++, j--) {
                        char tmp = buffer[i];
                        buffer[i] = buffer[j];
                        buffer[j] = tmp;
                    }
                }

                int result = write(1, buffer, idx);
                if (result == -1) {
                }
                total_char_to_print += idx;
            }
        }
        format++;
    }

    va_end(list_of_args);
    return total_char_to_print;
}

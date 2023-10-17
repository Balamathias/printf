#include "main.h"

int _printf(const char *format, ...) {
  int total_char_to_print = 0;
  va_list list_of_args;

  if (format == NULL) {
    return -1;
  }
  va_start(list_of_args, format);

  while (*format) {
    if (*format != '%') {
      int result = write(1, format, 1);
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
        int character = va_arg(list_of_args, int);
        int result = write(1, &character, 1);
        if (result == -1) {
          
        }
        total_char_to_print++;
      } else if (*format == 's') {
        char *str = va_arg(list_of_args, char *);
        int str_length = strlen(str);
        int result = write(1, str, str_length);
        if (result == -1) {
         
        }
        total_char_to_print += str_length;
      }

    }
    format++;
  }

  return total_char_to_print;
  va_end(list_of_args);
}


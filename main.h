#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);

typedef struct funcs
{
    char c;
    int (*f)(va_list);
} funcs_t;

int get_func(char s, va_list ap);
int print_percent(va_list ap);
int print_char(va_list ap);
int print_string(va_list ap);
int print_int(va_list ap);

#endif /* MAIN_H */
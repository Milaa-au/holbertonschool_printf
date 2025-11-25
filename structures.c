#include "main.h"
#include <stdarg.h>
#include <stddef.h>

int get_func(char s, va_list ap)
{
    int i = 0;

    funcs_t funcs[] = {
        {'c', print_char},
        {'s', print_string},
        {'%', print_percent},
        {'d', print_int},
        {'i', print_int},
        {'\0', NULL}
    };

    while (funcs[i].c)
    {
        if (funcs[i].c == s)
            return funcs[i].f(ap);
        i++;
    }

    return -1;
}
#include "main.h"
#include <stdarg.h>
#include <stdio.h>


funcs_t tab[] = {
    {'c', afficher_caractere},
    {'s', afficher_chaine},
    {'%', afficher_pourcent},
    {'d', afficher_entier},
    {'i', afficher_entier},
    {0, NULL}
};

int (*get_func(char c))(va_list)
{
    int i = 0;
    while (tab[i].c)
    {
        if (tab[i].c == c)
            return tab[i].f;
        i++;
    }
    return NULL;
}

int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, nb_affiches = 0;
    int (*func_ptr)(va_list);

    if (!format)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            if (!format[i])
            {
                va_end(args);
                return -1;
            }

            func_ptr = get_func(format[i]);
            if (func_ptr)
                nb_affiches += func_ptr(args);
            else
            {
                putchar('%');
                putchar(format[i]);
                nb_affiches += 2;
            }
        }
        else
        {
            putchar(format[i]);
            nb_affiches++;
        }
        i++;
    }

    va_end(args);
    return nb_affiches;
}

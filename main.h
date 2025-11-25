#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);

int afficher_caractere(va_list args);
int afficher_chaine(va_list args);
int afficher_pourcent(va_list args);
int afficher_entier(va_list args);

typedef struct funcs
{
    char c;
    int (*f)(va_list);
} funcs_t;

#endif

#include "main.h"

int afficher_caractere(va_list args)
{
    char c = (char)va_arg(args, int);
    write(1, &c, 1);
    return (1);
}

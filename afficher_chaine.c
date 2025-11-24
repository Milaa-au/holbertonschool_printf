#include "main.h"

/**
 * afficher_chaine - Affiche une chaîne de caractères
 * @args: liste d'arguments variable
 *
 * Return: nombre de caractères affichés
 */
int afficher_chaine(va_list args)
{
    char *str = va_arg(args, char *);
    int i = 0;

    if (!str)
        str = "(null)";

    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }

    return (i);
}

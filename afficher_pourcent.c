#include "main.h"

/**
 * afficher_pourcent - Affiche un caractère '%'
 *
 * Return: toujours 1
 */
int afficher_pourcent(void)
{
    write(1, "%", 1);
    return (1);
}

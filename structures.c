#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * get_func - Sélectionne et exécute la fonction correspondant à un spéci
 * @s: Caractère représentant le spécificateur de format
 * @ap: Liste d’arguments variadiques à transmettre à la fonction trouvée
 *
 * Description: Cette fonction parcourt un tableau de structures contenant
 * les spécificateurs pris en charge et les fonctions associées. Lorsqu’un
 * spécificateur correspond à celui fourni en argument, la fonction associée
 * est appelée avec les arguments variadiques.
 *
 * Return: Le résultat retourné par la fonction trouvée. Retourne -1 si
 * aucun spécificateur correspondant n’est trouvé.
 */

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
		{
			return (funcs[i].f(ap));
		}
		i++;
	}

	return (-1);
}

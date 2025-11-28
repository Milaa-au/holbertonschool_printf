#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
* _printf - Imprime une chaîne formatée selon des spécificateurs donnés.
* @format: Chaine de format contenant les caractères et spéci à traiter
*
* Description: Cette fonction parcourt la chaîne de format et imprime
* chaque caractère. Lorsqu'un caractère '%' est rencontré, elle appelle
* la fonction get_func afin de traiter le spécificateur correspondant
* et d’imprimer la valeur adaptée. Si le spécificateur n’est pas valide,
* le caractère '%' ainsi que le caractère suivant sont imprimés tels quels.
*
* Return: Le nombre total de caractères imprimés. Retourne -1 si format
* est NULL.
*/

int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, temp;

	if (format == NULL)
	{
		return (-1);
	}

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			count++;
			i++;
		}
		else
		{
			i++;
			if (format[i] == '\0')
			{
				va_end(args);
				return (-1);
			}

			temp = get_func(format[i], args);

			if (temp == -1)
			{
				count += putchar('%');
				count += putchar(format[i]);
			}
			else
			{
				count += temp;
			}
			i++;
		}
		
	}

	va_end(args);
	return (count);
}

#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - Imprime un caractère
 * @ap: Liste d'arguments variadiques contenant le caractère à imprimer
 *
 * Return: Toujours 1, correspondant au nombre de caractères imprimés.
 */

int print_char(va_list ap)
{
	char c = (char)va_arg(ap, int);

	putchar (c);
	return (1);
}

/**
 * print_percent - Imprime le caractère '%'
 * @ap: Liste d'arguments variadiques (non utilisée)
 *
 * Return: Toujours 1, correspondant au nombre de caractères imprimés.
 */

int print_percent(va_list ap)
{
    (void)ap;
    putchar('%');
    return (1);
}

/**
 * print_string - Imprime une chaîne de caractères
 * @ap: Liste d'arguments variadiques contenant la chaîne à imprimer
 *
 * Description: Si la chaîne reçue est NULL, la fonction imprime "(null)".
 * La fonction parcourt ensuite la chaîne et imprime chaque caractère.
 *
 * Return: Le nombre total de caractères imprimés.
 */

int print_string(va_list ap)
{
	char *str = va_arg(ap, char *);
	int len = 0;

	if (str == NULL)
	{
		str = "(null)";
	}

	while (str[len] != '\0')
	{
		putchar(str[len]);
		len++;
	}

	return (len);
}

/**
 * print_int - Imprime un entier sous forme décimale
 * @ap: Liste d'arguments variadiques contenant l'entier à imprimer
 *
 * Description: La fonction gère les entiers négatifs, imprime un tiret
 * si nécessaire, puis convertit le nombre en chaîne en stockant chaque
 * chiffre dans un buffer temporaire avant de les afficher dans l'ordre
 * correct.
 *
 * Return: Le nombre total de caractères imprimés.
 */

int print_int(va_list ap)
{
	int integer = va_arg(ap, int);
	char len[12];
	int i = 0, j, number = 0;
	unsigned int num;

	if (integer < 0)
	{
		putchar('-');
		number++;
		num = -integer;
	}
	else
	{
		num = integer;
	}

	if (num == 0)
	{
		len[i++] = '0';
	}
	while (num > 0)
	{
		len[i++] = (num % 10) + '0';
		num /= 10;
	}
	for (j = i - 1; j >= 0; j--)
	{
		putchar(len[j]);
		number++;
	}
	return (number);
}

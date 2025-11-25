#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int print_char(va_list ap)
{
    char c = (char)va_arg(ap, int);
    return (write(1, &c, 1));
}

int print_percent(va_list ap)
{
    (void)ap;
    return (write(1, "%", 1));
}

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
        len++;
    }
    write(1, str, len);
    return (len);
}

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
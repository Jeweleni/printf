#include "main.h"

/**
 * _printf - A function that produces output according to a format.
 * @format: A character string composed of zero or more directives.
 * Return: Number of characters printed (excluding null byte)
 */

int _printf(const char *format, ...)
{
	int no_of_char = 0;
	va_list arg_list;

	if (format == NULL)
		return (-1);
	va_start(arg_list, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			switch (*(format + 1))
			{
				case '%':
					no_of_char += write(1, format, 1);
					break;
				case 'c':
				{
					char c = (char)va_arg(arg_list, int);

					no_of_char += write(1, &c, 1);
					break;
				}
				case 's':
				{
					char *str = va_arg(arg_list, char *);

					if (str != NULL)
						no_of_char += write(1, str, strlen(str));
					else
						no_of_char += write(1, "(null)", 6);
					break;
				}
			}
			format += 2;
		}
		else
		{
			no_of_char += write(1, format++, 1);
		}
	}
	va_end(arg_list);
	return (no_of_char);
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */

int main(void)
{
	_printf("Character:[%c]\n", 'H');
	_printf("String:[%s]\n", "I am a string !");
	_printf("Percent:[%%]\n");
	return (0);
}

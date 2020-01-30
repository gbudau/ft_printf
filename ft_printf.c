#include "ft_printf.h"

int	ft_printf(const char *fmt, ...)
{
	int	out;
	va_list	ap;

	out = 0;
	va_start(ap, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			if (*(fmt) == 's')
				out += printf("%s", va_arg(ap, char *));
			else if (*fmt == 'd')
				out += printf("%d", va_arg(ap, int));
			else
				out += printf("%c", va_arg(ap, int));
		}
		else
			out += printf("%c", *fmt);
		fmt++;
	}
	va_end(ap);
	return (out);
}

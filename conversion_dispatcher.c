#include "ft_printf.h"

void	conversion_dispatcher(char c, t_specifier *specifier)
{
	if (c == 'c')
		parse_char(specifier, (char)va_arg(specifier->args, int));
	else if (c == 's')
		parse_str(specifier, va_arg(specifier->args, char *));
	else if (c == 'p')
		parse_hex(specifier, va_arg(specifier->args, unsigned long), c);
	else if (c == 'd' || c == 'i')
		parse_int(specifier, va_arg(specifier->args, int));
	else if (c == 'u')
		parse_unsigned(specifier, va_arg(specifier->args, unsigned int));
	else if (c == 'x' || c =='X')
		parse_hex(specifier, va_arg(specifier->args, unsigned int), c);
	else if (c == '%')
		parse_percent(specifier);
}

#include "ft_printf.h"

void	parse_unsigned(t_specifier *specifier)
{
	char				*str;
	unsigned long long	input;

	input = va_arg(specifier->args, unsigned int);
	str = int_handler(input, specifier, "0123456789");
	width_handler(specifier, str, ft_strlen(str));
}
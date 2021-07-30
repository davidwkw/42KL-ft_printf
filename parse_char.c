#include "ft_printf.h"

void	parse_char(t_specifier *specifier)
{
	char	input;

	input = (char)va_arg(specifier->args, int);
	specifier->fmt_str = str_create(input, 1);
	width_handler(specifier);
}

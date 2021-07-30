#include "ft_printf.h"

void	parse_char(t_specifier *specifier)
{
	char	input;

	input = (char)va_arg(specifier->args, int);
	if (!input)
		input = (specifier->is_nullc = 1);
	specifier->fmt_str = str_create(input, 1);
	width_handler(specifier);
}

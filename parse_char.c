#include "ft_printf.h"

void	parse_char(t_specifier *specifier, char input)
{
	if (!input)
		input = (specifier->is_nullc = 1);
	specifier->fmt_str = str_create(input, 1);
	width_handler(specifier);
}

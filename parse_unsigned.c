#include "ft_printf.h"

void	parse_unsigned(t_specifier *specifier, unsigned long long input)
{
	specifier->fmt_str = int_handler(input, specifier, "0123456789");
	width_handler(specifier);
}

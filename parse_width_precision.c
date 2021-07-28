#include "ft_printf.h"

void	parse_width_precision(char d, t_specifier *specifier, char mode)
{
	if (mode == 'w')
		specifier->flags.width = specifier->flags.width * 10 + (d - '0');
	else if (mode == 'p')
		specifier->flags.prec = specifier->flags.prec * 10 + (d - '0');
}

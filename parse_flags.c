#include "ft_printf.h"

void	parse_flags(char flag, t_specifier *specifier)
{
	if (flag == '-')
		specifier->flags.pad_zero = !(specifier->flags.pad_right = 1);
	else if (flag == '+')
		specifier->flags.prepend_space = !(specifier->flags.pos = 1);
	else if (flag == ' ')
		specifier->flags.prepend_space = (!specifier->flags.pos);
	else if (flag == '#')
		specifier->flags.alt_form = 1;
	else if (flag == '0')
		specifier->flags.pad_zero = (!specifier->flags.pad_right);
}
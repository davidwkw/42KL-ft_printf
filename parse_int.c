#include "ft_printf.h"

void	parse_int(t_specifier *specifier)
{
	char		*str;
	long long	input;
	int			total_precision;

	input = va_arg(specifier->args, int);
	if (input < 0)
		specifier->flags.prepend_space = 0;
	str = int_handler(input, specifier, "0123456789");
	total_precision = ft_strlen(str);
	width_handler(specifier, str, total_precision);
}
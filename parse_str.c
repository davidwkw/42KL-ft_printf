#include "ft_printf.h"

void	parse_str(t_specifier *specifier)
{
	char			*str;
	unsigned int	total_precision;

	str = va_arg(specifier->args, char *);
	total_precision = ft_strlen(str);
	if (specifier->flags.f_prec && (total_precision > specifier->flags.prec))
		total_precision = specifier->flags.prec;
	width_handler(specifier, str, total_precision);
}

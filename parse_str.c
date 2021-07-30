#include "ft_printf.h"

void	parse_str(t_specifier *specifier)
{
	char			*input;
	unsigned int	total_precision;

	input = va_arg(specifier->args, char *);
	if (!input)
		input = "(null)";
	else if (!input && specifier->flags.f_prec)
		input = "";
	total_precision = ft_strlen(input);
	if (specifier->flags.f_prec && (specifier->flags.prec < total_precision))
		total_precision = specifier->flags.prec;
	specifier->fmt_str = ft_strndup(input, total_precision);
	width_handler(specifier);
}

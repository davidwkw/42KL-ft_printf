#include "ft_printf.h"

t_flags	reset_flags(void)
{
	return ((t_flags){
		.pos = 0,
		.pad_right = 0,
		.prepend_space = 0,
		.pad_zero = 0,
		.alt_form = 0,
		.sign = 0,
		.f_prec = 0,
		.width = 0,
		.prec = 0
	});
}

size_t	validate_specifier(t_specifier *specifier)
{
	unsigned int	i;

	i = 1;
	while (ft_strchr(FLAGS, specifier->format[i]))
		parse_flags(specifier->format[i++], specifier);
	while (ft_isdigit(specifier->format[i]))
		parse_width_precision(specifier->format[i++], specifier, 'w');
	if (ft_strchr(".", specifier->format[i]))
	{
		specifier->flags.f_prec = 1;
		i++;
	}
	while (ft_isdigit(specifier->format[i]))
		parse_width_precision(specifier->format[i++], specifier, 'p');
	if (ft_strchr("cspdiuxXn%", specifier->format[i]))
	{
		specifier->is_valid = 1;
		conversion_dispatcher(specifier->format[i++], specifier);
	}
	return (i);
}

void	parse_format(t_specifier *specifier)
{
	size_t	i;

	i = 0;
	i += validate_specifier(specifier);
	if (!specifier->is_valid)
		specifier->nprint += write(1, specifier->format, i);
	specifier->format += i - 1;
	specifier->is_valid = 0;
	specifier->flags = reset_flags();
}
#include "ft_printf.h"

void	parse_char(t_specifier *specifier)
{
	char	str[2];

	str[0] = (char)va_arg(specifier->args, int);
	str[1] = '\0';
	width_handler(specifier, ft_strdup(str), 1);
}
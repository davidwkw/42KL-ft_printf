#include "ft_printf.h"

void	parse_char(t_specifier *specifier)
{
	specifier->fmt_str = str_create((char)va_arg(specifier->args, int), 1);
	width_handler(specifier);
}

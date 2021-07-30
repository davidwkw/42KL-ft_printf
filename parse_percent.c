#include "ft_printf.h"

void	parse_percent(t_specifier *specifier)
{
	specifier->fmt_str = ft_strdup("%");
	width_handler(specifier);
}

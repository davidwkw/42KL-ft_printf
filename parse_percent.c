#include "ft_printf.h"

void	parse_percent(t_specifier *specifier)
{
	width_handler(specifier, "%", 1);
}

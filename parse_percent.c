#include "ft_printf.h"

void	parse_percent(t_specifier *format)
{
	format->nprint += write(1, "%", ft_strlen("%"));
}
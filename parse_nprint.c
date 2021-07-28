#include "ft_printf.h"

void	parse_nprint(t_specifier *specifier)
{
	unsigned long	*container;

	container = va_arg(specifier->args, void *);
	*container = specifier->nprint;
}
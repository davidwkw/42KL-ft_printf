#include "ft_printf.h"

static void	init_specifier(t_specifier *specifier, const char *format_str)
{
	specifier->format = format_str;
	specifier->is_valid = 0;
	specifier->flags = reset_flags();
	specifier->nprint = 0;
	specifier->fmt_str = NULL;
}

int	ft_printf(const char *format, ...)
{
	t_specifier	specifier;

	va_start(specifier.args, format);
	init_specifier(&specifier, format);
	while (*specifier.format)
	{
		if (*specifier.format == '%')
			parse_format(&specifier);
		else
			specifier.nprint += write(1, specifier.format++, 1);
	}
	va_end(specifier.args);
	return (specifier.nprint);
}

#include "ft_printf.h"

static char	*prepend_alt(t_specifier *specifier, char mode, unsigned long input)
{
	if (!input && (mode == 'x' || mode == 'X'))
		return (ft_strdup(""));
	if ((specifier->flags.alt_form && mode == 'x') || mode == 'p')
		return (ft_strdup("0x"));
	else if (specifier->flags.alt_form && mode == 'X')
		return (ft_strdup("0X"));
	else
		return (ft_strdup(""));
}

static char	*base_handler(char mode)
{
	char	*base;

	base = NULL;
	if (mode == 'x' || mode == 'p')
		base = "0123456789abcdef";
	else if (mode == 'X')
		base = "0123456789ABCDEF";
	return (base);
}

void	parse_hex(t_specifier *specifier, unsigned long input, char mode)
{
	char			*base_str;
	char			*new_str;
	char			*alt_form;

	base_str = NULL;
	alt_form = prepend_alt(specifier, mode, input);
	base_str = base_handler(mode);
	specifier->fmt_str = hex_handler(input, specifier, base_str);
	new_str = ft_strjoin(alt_form, specifier->fmt_str);
	free(alt_form);
	free(specifier->fmt_str);
	specifier->fmt_str = new_str;
	width_handler(specifier);
}

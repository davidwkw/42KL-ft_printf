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

void	parse_hex(t_specifier *specifier, char mode)
{
	char			*str;
	char			*base_str;
	unsigned long	input;
	char			*new_str;
	char			*alt_form;

	base_str = NULL;
	if (mode == 'p')
		input = va_arg(specifier->args, unsigned long);
	else
	input = va_arg(specifier->args, unsigned int); 
	alt_form = prepend_alt(specifier, mode, input);
	base_str = base_handler(mode);
	str = hex_handler(input, specifier, base_str);
	new_str = ft_strjoin(alt_form, str);
	free(alt_form);
	free(str);
	width_handler(specifier, new_str, ft_strlen(new_str));
}
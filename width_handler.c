#include "ft_printf.h"

static void	pad(t_specifier *specifier, char c, int *len)
{
	while (*len > 0)
	{
		specifier->nprint += write(1, &c, 1);
		(*len)--;
	}
}

void	width_handler(t_specifier *specifier, char *str, size_t str_len)
{
	int		width_diff;
	char	pad_char;

	pad_char = ' ';
	if (specifier->flags.pad_zero)
		pad_char = '0';
	width_diff = specifier->flags.width - str_len - specifier->flags.sign;
	if (specifier->flags.pad_zero)
		pad(specifier, pad_char, &width_diff);
	if (width_diff > 0 && !specifier->flags.pad_right)
		pad(specifier, pad_char, &width_diff);
	specifier->nprint += write(1, str, str_len);
	if (specifier->flags.pad_right)
		pad(specifier, pad_char, &width_diff);
}

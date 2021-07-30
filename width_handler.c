#include "ft_printf.h"

void	width_handler(t_specifier *specifier)
{
	int				width_diff;
	char			pad_char;
	char			*pad_str;
	unsigned int	str_len;
	char			*temp;

	temp = NULL;
	str_len = specifier->is_c || ft_strlen(specifier->fmt_str);
	pad_char = ' ';
 	if (specifier->flags.pad_zero)
 		pad_char = '0';
	else if (!specifier->flags.pad_zero)
		specifier->flags.sign = 0;
	width_diff = specifier->flags.width - str_len - specifier->flags.sign;
	if (width_diff > 0)
		pad_str = str_create(pad_char, width_diff);
	else
		pad_str = ft_strdup("");
	if (!specifier->flags.pad_right)
 		temp = ft_strjoin(pad_str, specifier->fmt_str);
	else if (specifier->flags.pad_right)
		temp = ft_strjoin(specifier->fmt_str, pad_str);
	free(specifier->fmt_str);
	free(pad_str);
	specifier->fmt_str = temp;
}
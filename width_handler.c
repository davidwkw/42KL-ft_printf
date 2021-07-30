#include "ft_printf.h"

static char	pad_char_selector(t_specifier *specifier)
{
	if (specifier->flags.pad_zero)
		return ('0');
	return (' ');
}

static char	*append_width(t_specifier *specifier, char *pad_s)
{
	char	*temp;

	temp = NULL;
	if (!specifier->flags.pad_right)
		temp = ft_strjoin(pad_s, specifier->fmt_str);
	else if (specifier->flags.pad_right)
		temp = ft_strjoin(specifier->fmt_str, pad_s);
	return (temp);
}

void	width_handler(t_specifier *specifier)
{
	int				width_diff;
	char			pad_char;
	char			*pad_str;
	unsigned int	str_len;
	char			*temp;

	temp = NULL;
	str_len = ft_strlen(specifier->fmt_str);
	pad_char = pad_char_selector(specifier);
	if (!specifier->flags.pad_zero)
		specifier->flags.sign = 0;
	width_diff = specifier->flags.width - str_len - specifier->flags.sign;
	if (width_diff > 0)
		pad_str = str_create(pad_char, width_diff);
	else
		pad_str = ft_strdup("");
	temp = append_width(specifier, pad_str);
	free(specifier->fmt_str);
	free(pad_str);
	specifier->fmt_str = temp;
}

#include "ft_printf.h"

char	*hex_handler(unsigned long input, t_specifier *specifier, char *base)
{
	char			*str;
	char			*new_str;
	char			*initial_str;
	unsigned int	str_len;

	str = ft_llutoa_base(input, base);
	if (!input && specifier->flags.f_prec)
		str = ft_strdup("");
	str_len = ft_strlen(str);
	if (specifier->flags.f_prec && str_len < specifier->flags.prec)
		initial_str = str_create('0', specifier->flags.prec - str_len);
	else
		initial_str = ft_strdup("");
	new_str = ft_strjoin(initial_str, str);
	free(str);
	free(initial_str);
	return (new_str);
}

#include "ft_printf.h"

static void	prepend_sign(t_specifier *specifier, long long input)
{
	if (input < 0)
		specifier->nprint += write(1, "-", 1);
	else if (specifier->flags.pos)
		specifier->nprint += write(1, "+", 1);
	else if (specifier->flags.prepend_space)
		specifier->nprint += write(1, " ", 1);
	else
		return ;
	specifier->flags.sign = 1;
	return ;
}	

char	*int_handler(long long input, t_specifier *specifier, char *base_str)
{
	char	*str;
	char	*new_str;
	char	*initial_str;
	int		str_len;

	prepend_sign(specifier, input);
	if (input < 0)
		str = ft_llutoa_base(input * -1, base_str);
	else
		str = ft_llutoa_base(input, base_str);
	str_len = ft_strlen(str);
	if (specifier->flags.f_prec && str_len < specifier->flags.prec)
		initial_str = str_create('0', specifier->flags.prec - str_len);
	else
		initial_str = ft_strdup("");
	new_str = ft_strjoin(initial_str, str); 
	free(initial_str);
	free(str);
	return (new_str);
}

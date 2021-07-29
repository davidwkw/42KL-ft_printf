#include "ft_printf.h"

static char	*sign_selector(t_specifier *specifier, long long input)
{
	char	*str;

	if (input < 0)
		str = ft_strdup("-");
	else if (specifier->flags.pos)
		str = ft_strdup("+");
	else if (specifier->flags.prepend_space)
		str = ft_strdup(" ");
	else
		str = ft_strdup("");
	return (str);
}

static char	*prepend_sign(char *sign, char *str)
{
	char	*new_str;

	new_str = ft_strjoin(sign, str);
	free(sign);
	free(str);
	return (new_str);
}

char	*int_handler(long long input, t_specifier *specifier, char *base_str)
{
	char			*str;
	char			*new_str;
	char			*initial_str;
	unsigned int	str_len;
	char			*sign;

	if (!input && specifier->flags.f_prec)
		str = ft_strdup("");
	else if(input < 0)
		str = ft_llutoa_base(input * -1, base_str);
	else
		str = ft_llutoa_base(input, base_str);
	str_len = ft_strlen(str);
	sign = sign_selector(specifier, input);
	if (specifier->flags.f_prec)
		specifier->flags.pad_zero = 0;
	if (specifier->flags.f_prec && str_len < specifier->flags.prec)
		initial_str = str_create('0', specifier->flags.prec - str_len);
	else
		initial_str = ft_strdup("");
	new_str = prepend_sign(sign, ft_strjoin(initial_str, str));
	free(str);
	free(initial_str);
	return (new_str);
}

#include "ft_printf.h"

static char	*prepend_sign(t_specifier *specifier, long long input)
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

char	*int_handler(long long input, t_specifier *specifier, char *base_str)
{
	char			*str;
	char			*new_str;
	char			*initial_str;
	unsigned int	str_len;
	char			*temp;

	if (!input && specifier->flags.f_prec)
		str = ft_strdup("");
	else if(input < 0)
		str = ft_llutoa_base(input * -1, base_str);
	else
		str = ft_llutoa_base(input, base_str);
	str_len = ft_strlen(str);
	temp = prepend_sign(specifier, input);
	if (specifier->flags.f_prec && str_len < specifier->flags.prec)
		initial_str = str_create('0', specifier->flags.prec - str_len);
	else
		initial_str = ft_strdup("");
	new_str = ft_strjoin(temp, initial_str);
	free(initial_str);
	free(temp);
	temp = ft_strjoin(new_str, str);
	free(str);
	free(new_str);
	return (temp);
}

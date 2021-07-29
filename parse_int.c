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

void	parse_int(t_specifier *specifier)
{
	char		*str;
	long long	input;
	char		*sign;
	char		*new_str;

	input = va_arg(specifier->args, int);
	if (input < 0)
		specifier->flags.prepend_space = 0;
	sign = sign_selector(specifier, input);
	str = int_handler(input, specifier, "0123456789");
	new_str = prepend_sign(sign, str);
	width_handler(specifier, new_str, ft_strlen(str));
	free(new_str);
}

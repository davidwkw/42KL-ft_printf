#include "ft_printf.h"

static char	*sign_selector(t_specifier *specifier, long long input)
{
	char	*str;

	if (input < 0)
	{
		str = ft_strdup("-");
		specifier->flags.prepend_space = 0;
	}
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
	return (new_str);
}

void	parse_int(t_specifier *specifier)
{
	char		*str;
	long long	input;
	char		*sign;
	char		*new_str;
	int			len;

	input = va_arg(specifier->args, int);
	sign = sign_selector(specifier, input);
	str = int_handler(input, specifier, "0123456789");
	len = ft_strlen(str);
	if (!specifier->flags.pad_zero)
	{
		new_str = prepend_sign(sign, str);
		free(str);
	}
	else
	{
		new_str = str;
		specifier->nprint += write(1, sign, len);
		len += 1;
	}
	width_handler(specifier, new_str, len);
	free(new_str);
	free(sign);
}

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
		return (ft_strdup(""));
	specifier->flags.sign = 1;
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
	long long	input;
	char		*sign;
	char		*temp;

	input = va_arg(specifier->args, int);
	sign = sign_selector(specifier, input);
	specifier->fmt_str = int_handler(input, specifier, "0123456789");
	if (!specifier->flags.pad_zero)
	{
		temp = prepend_sign(sign, specifier->fmt_str);
		free(specifier->fmt_str);
		specifier->fmt_str = temp;
	}
	width_handler(specifier);
	if (specifier->flags.pad_zero)
	{
		temp = prepend_sign(sign, specifier->fmt_str);
		free(specifier->fmt_str);
		specifier->fmt_str = temp;
	}
}

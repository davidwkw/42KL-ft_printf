#include "ft_printf.h"

t_flags	reset_flags(void)
{
	return ((t_flags){
		.pos = 0,
		.pad_right = 0,
		.prepend_space = 0,
		.pad_zero = 0,
		.alt_form = 0,
		.f_prec = 0,
		.sign = 0,
		.width = 0,
		.prec = 0
	});
}

static size_t	validate_specifier(t_specifier *specifier)
{
	unsigned int	i;

	i = 1;
	while (ft_strchr(FLAGS, specifier->format[i]))
		parse_flags(specifier->format[i++], specifier);
	while (ft_isdigit(specifier->format[i]))
		parse_width_precision(specifier->format[i++], specifier, 'w');
	if (specifier->format[i] == '.')
		parse_flags(specifier->format[i++], specifier);
	while (ft_isdigit(specifier->format[i]))
		parse_width_precision(specifier->format[i++], specifier, 'p');
	if (ft_strchr("cspdiuxX%", specifier->format[i]) && specifier->format[i])
	{
		specifier->is_valid = 1;
		conversion_dispatcher(specifier->format[i++], specifier);
	}
	return (i);
}

static void	ft_strreplace(char *str, char s, char r)
{
	while (*str)
	{
		if (*str == s)
			*str = r;
		str++;
	}
}

void	parse_format(t_specifier *specifier)
{
	long			i;
	unsigned int	str_len;

	i = 0;
	i += validate_specifier(specifier);
	if (!specifier->is_valid)
		specifier->fmt_str = ft_strndup(specifier->format, i);
	str_len = ft_strlen(specifier->fmt_str);
	if (specifier->is_nullc)
		ft_strreplace(specifier->fmt_str, specifier->is_nullc, '\0');
	specifier->nprint += write(1, specifier->fmt_str, str_len);
	free(specifier->fmt_str);
	specifier->format += i;
	specifier->is_valid = 0;
	specifier->is_nullc = 0;
	specifier->flags = reset_flags();
	specifier->fmt_str = NULL;
}

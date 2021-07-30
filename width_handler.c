#include "ft_printf.h"

static char	pad_char_selector(t_specifier *specifier)
{
	if (specifier->flags.pad_zero)
 		return ('0');
	return (' ');
}

static char *null_join(char *s1, char *s2)
{
	char			*joinedstr;
	unsigned int	i;

	if (s1 && s2)
	{
		joinedstr = malloc(sizeof(char) * (ft_strlen(s1) + 1 + 1));
		if (!joinedstr)
			return (joinedstr);
		i = 0;
		while (s1[i])
		{
			joinedstr[i] = s1[i];
			i++;
		}
		joinedstr[i + 1] = '\0';
		joinedstr[i + 2] = '\0';
		return (joinedstr);
	}
	return (ft_strdup(""));
}

static char	*append_width(t_specifier *specifier, char *pad_s)
{
	char	*temp;

	temp = NULL;
	if (specifier->is_nullc)
		temp = null_join(pad_s, specifier->fmt_str);
	else if (!specifier->flags.pad_right)
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
	str_len = ft_strlen(specifier->fmt_str) + specifier->is_nullc;
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
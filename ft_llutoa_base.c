#include "ft_printf.h"

static int	is_base_valid(char *base)
{
	int	i;
	int	j;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] < 32)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static size_t	ft_nbrlen(unsigned long long n, unsigned int base)
{
	size_t	len;

	len = 1;
	while (n >= base)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_llutoa_base(unsigned long long n, char *base_str)
{
	char			*str;
	int				len;
	unsigned int	base;

	if (!is_base_valid(base_str))
		return (ft_strdup(""));
	base = ft_strlen(base_str);
	len = ft_nbrlen(n, base);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (str);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = base_str[n % base];
		n /= base;
	}
	return (str);
}

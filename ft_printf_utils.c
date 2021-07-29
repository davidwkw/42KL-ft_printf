#include "ft_printf.h"

char	*str_create(int c, int len)
{
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	ft_memset(str, c, len);
	str[len] = '\0';
	return (str);
}

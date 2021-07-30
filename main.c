#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	main(void)
{
	char c;
	int i;
	int j;
	i = printf("%c\n", '0');  //s == ('0'), p == (nil)
	printf("starting ft_version\n");
	j = ft_printf("%c\n", '0');
	printf("i %d\n", i);
	printf("j %d\n", j);
}

#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

int	main(void)
{
	char c;
	int i;
	int j;
	// cspdiuxX%
	// i = printf("%-5\n");
	// i = printf("hello,c |%c|.\n", NULL);  //s == (null), p == (nil)
	// i = printf("hello,s |%.c|.\n", 'd');  //s == (null), p == (nil)
	// i = printf("hello,p %.p.\n", NULL);  //s == (null), p == (nil)
	i = printf("|% 07d| \n", 14);  //s == (null), p == (nil)
	// i = printf("hello,i %i.\n", NULL);  //s == (null), p == (nil)
	// i = printf("helo,u %.2u.\n", 0);  //s == (null), p == (nil)
	// i = printf("hello,x %#.x.\n", NULL);  //s == (null), p == (nil)
	// i = printf("hello,X %X.\n", NULL);  //s == (null), p == (nil)
	// i = printf("hello,% %%.  what the fuck\n", NULL);  //s == (null), p == (nil)
	printf("starting ft_version\n");
	// j = ft_printf("%-5\n");
	// j = ft_printf("hello,c |%c|.\n", NULL);
	// j = ft_printf("hello,s |%.c|.\n", 'd');
	// j = ft_printf("hello,p %.p.\n", NULL);
	j = ft_printf("|% 07d| \n", 14);
	// j = ft_printf("hello,i %i.\n", NULL);
	// j = ft_printf("hello,u %.2u.\n", 0);
	// j = ft_printf("hello,x %#.x.\n", NULL);
	// j = ft_printf("hello,X %X.\n", NULL);
	// j = ft_printf("hello,% %%.  what the fuck\n", NULL);  //s == (null), p == (nil)
	printf("i %d\n", i);
	printf("j %d\n", j);
}

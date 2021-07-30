#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# define FLAGS "-+ #0"

typedef struct s_flags
{
	unsigned int	pos : 1;
	unsigned int	pad_right : 1;
	unsigned int	prepend_space : 1;
	unsigned int	pad_zero : 1;
	unsigned int	alt_form : 1;
	unsigned int	f_prec : 1;
	unsigned int	sign : 1;
	unsigned int	width;
	unsigned int	prec;
}	t_flags;

typedef struct s_specifier
{
	const char		*format;
	va_list			args;
	unsigned int	is_valid : 1;
	t_flags			flags;
	unsigned int	is_nullc : 1;
	int				nprint;
	char			*fmt_str;
}	t_specifier;

int		ft_printf(const char *format, ...);
void	parse_format(t_specifier *specifier);
t_flags	reset_flags(void);
void	parse_flags(char flag, t_specifier *specifier);
void	parse_width_precision(char c, t_specifier *specifier, char m);
void	conversion_dispatcher(char c, t_specifier *format);
void	width_handler(t_specifier *specifier);
char	*int_handler(long long input, t_specifier *specifier, char *base);
char	*hex_handler(unsigned long input, t_specifier *specifier, char *base);

void	parse_char(t_specifier *format);
void	parse_str(t_specifier *format);
void	parse_hex(t_specifier *format, char c);
void	parse_int(t_specifier *format);
void	parse_unsigned(t_specifier *format);
void	parse_percent(t_specifier *format);
void	parse_nprint(t_specifier *specifier);

char	*ft_llutoa_base(unsigned long long n, char *base_str);
char	*str_create(int c, int len);

#endif

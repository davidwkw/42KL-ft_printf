SRCS 	=	conversion_dispatcher.c \
			width_handler.c \
			parse_format.c \
			ft_llutoa_base.c \
			ft_printf.c \
			parse_char.c \
			parse_flags.c \
			parse_hex.c \
			parse_int.c \
			parse_percent.c \
			parse_str.c \
			parse_unsigned.c \
			parse_width_precision.c \
			int_handler.c \
			hex_handler.c \
			ft_printf_utils.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I.

RM = rm -f

AR = ar rcs

LIBFTDIR = ./libft

LIBFT = $(LIBFTDIR)/libft.a

all : $(NAME)

$(LIBFT):
	@make -C $(LIBFTDIR) all

$(NAME) : $(LIBFT) $(OBJS)
	@echo "Creating $(NAME)"
	@cp $(LIBFT) $@
	@$(AR) $(NAME) $(OBJS)

bonus : all

clean :
	@echo "Cleaning up $(OBJS)"
	@$(RM) $(OBJS)
	@make -C $(LIBFTDIR) clean

fclean : clean
	@echo "Cleaning up $(NAME)"
	@$(RM) $(NAME)
	@make -C $(LIBFTDIR) fclean

re : fclean all

.PHONY : all clean fclean re

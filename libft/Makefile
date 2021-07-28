# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwang <kwang@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/19 16:55:08 by kwang             #+#    #+#              #
#    Updated: 2021/07/13 14:20:10 by kwang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_strjoin.c \
		ft_isascii.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strlcat.c \
		ft_striteri.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c \

BNS_SRCS =	ft_lstnew.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstsize.c \
			ft_strndup_bonus.c \
			ft_strcpy_bonus.c \

OBJS = $(SRCS:.c=.o)

BNS_OBJS = $(BNS_SRCS:.c=.o)

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I.

RM = rm -f

AR = ar rcs

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creating lib file..."
	@$(AR) $(NAME) $(OBJS)

bonus: $(BNS_OBJS) $(NAME)
	@echo "Adding bonus functions..."
	@$(AR) $(NAME) $(BNS_OBJS)

clean:
	@echo "Cleaning up all .o files..."
	@$(RM) $(OBJS) $(BNS_OBJS)

fclean: clean
	@echo "Cleaning up $(NAME)"
	@$(RM) $(NAME)

re: fclean all
	@echo "Recompiling $(NAME)"

.PHONY: all re clean fclean bonus

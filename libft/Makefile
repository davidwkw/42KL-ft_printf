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

SRCS =	ft_strjoin.c \
		ft_isdigit.c \
		ft_memset.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strndup.c

OBJS = $(SRCS:.c=.o)

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

clean:
	@echo "Cleaning up all .o files..."
	@$(RM) $(OBJS)

fclean: clean
	@echo "Cleaning up $(NAME)"
	@$(RM) $(NAME)

re: fclean all
	@echo "Recompiling $(NAME)"

.PHONY: all re clean fclean bonus

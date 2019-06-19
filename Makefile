# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galiza <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/04 19:55:13 by galiza            #+#    #+#              #
#    Updated: 2019/06/09 21:01:34 by pcorlys-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_memset.c\
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strsplit.c \
	ft_itoa.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnstr.c \
	ft_putendl.c \
	ft_putnbr.c \
	ft_putun_nbr.c \
	ft_putchar_fd.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_count_if.c \
	ft_foreach.c \
	ft_sqrt.c \
	ft_iterative_power.c \
	ft_swap.c \
	ft_printf.c


PRINTF = print_c.c\
		 print_s.c\
		 print_p.c\
		 print_f.c\
		 print_d.c\
		 print_o.c\
		 print_u.c\
		 print_x.c\
		 print_bigx.c\
		 print_percent.c\
		 print_f_sec.c\
		 print_spaces.c\
		 print_get_keys.c

OBJ = $(SRC:.c=.o)
OBJPRINTF = $(PRINTF:.c=.o)

PRINTFDIR = srcs/utils
SRCDIR = srcs
OBJDIR = objs

OBJS = $(addprefix $(OBJDIR)/, $(OBJ))
OBJSPRINTF = $(addprefix $(OBJDIR)/, $(OBJPRINTF))
HEADER = -I ./includes

CC = gcc
CFLAGS = -c -Werror -Wextra -Wall

NAME = libftprintf.a

all: $(NAME)

$(OBJDIR)/%.o: $(PRINTFDIR)/%.c
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c 
	@/bin/mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(HEADER) $< -o $@

$(NAME): $(OBJS) $(OBJSPRINTF)
	@ar rcs $@ $^
	@ranlib $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

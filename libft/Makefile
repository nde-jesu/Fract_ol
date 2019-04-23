# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nde-jesu <nde-jesu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 15:08:50 by nde-jesu          #+#    #+#              #
#    Updated: 2019/04/23 15:32:56 by nde-jesu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra -Wconversion

SRC = ft_isalpha \
	  ft_isdigit \
	  ft_isalnum \
	  ft_isascii \
	  ft_isprint \
	  ft_tolower \
	  ft_toupper \
	  ft_strlen \
	  ft_strcpy \
	  ft_strncpy \
	  ft_strcat \
	  ft_strncat \
	  ft_strlcat \
	  ft_strdup \
	  ft_strstr \
	  ft_strnstr \
	  ft_strcmp \
	  ft_strncmp \
	  ft_strchr \
	  ft_strrchr \
	  ft_atoi \
	  ft_memset \
	  ft_bzero \
	  ft_memcpy \
	  ft_memccpy \
	  ft_memmove \
	  ft_memchr \
	  ft_memcmp \
	  ft_memalloc \
	  ft_memdel \
	  ft_strnew \
	  ft_strdel \
	  ft_strclr \
	  ft_striter \
	  ft_striteri \
	  ft_strmap \
	  ft_strmapi \
	  ft_strequ \
	  ft_strnequ \
	  ft_strsub \
	  ft_strjoin \
	  ft_strtrim \
	  ft_strsplit \
	  ft_itoa \
	  ft_putchar \
	  ft_putstr \
	  ft_putendl \
	  ft_putnbr \
	  ft_putchar_fd \
	  ft_putstr_fd \
	  ft_putendl_fd \
	  ft_putnbr_fd \
	  ft_lstnew \
	  ft_lstdelone \
	  ft_lstdel \
	  ft_lstadd \
	  ft_lstiter \
	  ft_lstmap \
	  ft_strndup \
	  ft_strrev \
	  ft_lstfind \
	  ft_lstiter_if \
	  ft_lstrev \
	  ft_intlen \
	  ft_lstlen \
	  ft_strrealloc \
	  ft_strccat \
	  ft_itoa_base \
	  get_next_line \
	  ft_swap \
	  ft_abs \
	  ft_strlowcase \
	  ft_max

OBJDIR = obj/
CLEANOBJDIR = OBJDIR
CLEANOBJ = OBJ

SRCDIR = srcs/

SRCNAME = $(addprefix $(SRCDIR), $(addsuffix .c, $(SRC)))

OBJ = $(addprefix $(OBJDIR), $(addsuffix .o, $(SRC)))

INCDIR = includes/

all: $(NAME)

.PHONY: all clean fclean re

$(OBJDIR)%.o:$(SRCDIR)%.c
		@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJ)
	@ar rcs $(NAME) $(OBJ)

clean:
		@rm -rf $(OBJ) $(OBJDIR)

fclean: clean
		@rm -f $(NAME)

re: fclean all


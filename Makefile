# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galy <galy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/09 15:00:23 by galy              #+#    #+#              #
#    Updated: 2018/06/07 12:00:46 by galy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libfts.a
CC		=	clang
#CFLAGS	=	-Wall -Werror -Wextra
# CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g
# CFLAGS	=	-fsanitize=address
NA		=	nasm
NAFLAG	=	-f macho64
LD		=	ld

####DIRECTORY####

SRCDIR		=	src
OBJDIR		=	obj
INCDIR		=	inc

####COLOR-SET####

CRESET		=	\033[0m
CRED		=	\033[31m
CGREEN		=	\033[32m
CGREEN+		=	\033[32;1;5m
CYELLOW		=	\033[33m
CYELLOW+	=	\033[33;1m
CBLUE		=	\033[34m
CBLUE+		=	\033[34;1m
CMAGENTA	=	\033[35m
CCYAN		=	\033[36m
CWHITE		=	\033[37m

####CURSOR-SET####

CUR_SVE		=	\033[s
CUR_RST		=	\033[u
CUR_CLR		=	\033[K

####SOURCE####

SRC			= \
	ft_tolower.s	ft_toupper.s	ft_bzero.s	\
	ft_strcat.s		ft_isalpha.s	ft_isdigit.s\
	ft_isalnum.s	ft_isascii.s	ft_isprint.s\
	ft_strlen.s		ft_puts.s		ft_memset.s	\
	ft_memcpy.s		ft_strdup.s		ft_cat.s	\
	ft_putstr_fd.s	ft_memchr.s


####FUNC####

OBJ			= $(SRC:.s=.o)
OBJP		= $(addprefix $(OBJDIR)/, $(SRC:.s=.o))


####RULEZ####

all			: OBJD $(NAME)
	@nasm -v

$(NAME) : $(OBJP)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $(SRCDIR)/main.c -o $(OBJDIR)/main.o
	@ar -rc $(NAME) $^
	$(CC) $(CFLAGS) $(OBJDIR)/main.o $^ -o main_test -L. -lfts

clean		:
	$(RM) -r $(OBJDIR)

mini_clean	:

fclean		: clean
	$(RM) $(NAME)
	$(RM) main_test

re			: fclean print_inter_line all


####MORE_RULEZ####

$(OBJDIR)/%.o: $(SRCDIR)/%.s
	$(NA) $(NAFLAG) $^ -o $@

test		:
	$(CC) -c $(SRCDIR)/main.c -o $(OBJDIR)/main.o

print_inter_line	:
	@printf "$(CBLUE+)	-----$(CRESET)	$(CWHITE)-----	$(CRED)-----$(CRESET)\n"

OBJD		:
	@mkdir -p $(OBJDIR)


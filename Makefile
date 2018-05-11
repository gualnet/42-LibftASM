# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galy <galy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/09 15:00:23 by galy              #+#    #+#              #
#    Updated: 2018/05/11 17:54:48 by galy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	
CFLAGS	=	-Wall -Werror -Wextra
# CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g
CC		=	clang
NA		=	nasm
LD		=	ld

####DIRECTORY####

SRCDIR		=	src
OBJDIR		=	objs
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
	ft_tolower.s


####FUNC####

DOT_O = $(SRC:.s=.o)


####RULEZ####

all			: OBJD
	@$(CC) -c $(SRCDIR)/main.c -o $(OBJDIR)/main.o
	@$(NA) -f macho64 $(SRCDIR)/$(SRC) -o $(OBJDIR)/$(SRC:.s=.o)
	@$(CC) $(OBJDIR)/main.o $(OBJDIR)/$(DOT_O)

clean		:
	$(RM) -r $(OBJDIR)

mini_clean	:

fclean		: clean
	$(RM) a.out

re			: fclean print_inter_line all


####MORE_RULEZ####

test		:
	$(CC) -c $(SRCDIR)/main.c -o $(OBJDIR)/main.o

print_inter_line	:
	@printf "$(CBLUE+)	-----$(CRESET)	$(CWHITE)-----	$(CRED)-----$(CRESET)\n"

OBJD		:
	@mkdir -p $(OBJDIR)


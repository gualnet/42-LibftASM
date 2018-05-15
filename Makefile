# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galy <galy@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/09 15:00:23 by galy              #+#    #+#              #
#    Updated: 2018/05/15 09:24:31 by galy             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libfts.a
CC		=	clang
CFLAGS	=	-Wall -Werror -Wextra
# CFLAGS	=	-Wall -Werror -Wextra -fsanitize=address -g
NA		=	/usr/local/bin/nasm
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
	ft_strcat.s


####FUNC####

OBJ			= $(SRC:.s=.o)
OBJP		= $(addprefix $(OBJDIR)/, $(SRC:.s=.o))


####RULEZ####

all			: OBJD $(NAME)
	@nasm -v

$(NAME) : $(OBJP)
	$(CC) -I$(INCDIR) -c $(SRCDIR)/main.c -o $(OBJDIR)/main.o
	@ar -rc $(NAME) $^
	$(CC) $(OBJDIR)/main.o $^ -o main_test -L. -lfts
#	@echo $@
#	@echo $(SRC)
#	@echo $(OBJ)
#	@echo $?
#	@echo $^
#	@echo $(OBJP)

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


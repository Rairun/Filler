# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaprono <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 11:41:27 by psaprono          #+#    #+#              #
#    Updated: 2018/07/23 18:47:46 by psaprono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := 	psaprono.filler

SRC :=		parse.c algo.c

OBJ =		$(SRC:.c=.o)

LIBFT =			$(LIBFT_DIR)libft.a
LIBFT_DIR :=	libft/
LIBFT_FLAGS :=	-lft -L $(LIBFT_DIR)

CC_FLAGS :=		-Wall -Werror -Wextra

LINK_FLAGS :=	$(LIBFT_FLAGS)

HEADER_FLAGS :=	-I. -I $(LIBFT_DIR)

CC :=			gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) filler.h
	@$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)

$(OBJ_DIR)%.o: %.c
	@$(CC) -O3 -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

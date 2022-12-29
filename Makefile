# **************************************************************************** #
#                                                                            #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsmereka <gsmereka@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 18:51:39 by gsmereka          #+#    #+#              #
#    Updated: 2022/11/28 09:47:39 by gsmereka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME			=	pipex_bonus


HEADERS			=	./headers/pipex_bonus.h ./headers/objects_bonus.h ./headers/utils.h 

CFLAGS			=	-Wall -Wextra -Werror

SRC				=	./src_bonus/pipex_bonus.c ./src_bonus/check_args_bonus.c ./src_bonus/finalize_bonus.c \
					./src_bonus/set_cmds_bonus.c ./src_bonus/redirect_bonus.c ./src_bonus/set_processes_bonus.c \
					./src_bonus/initialize_bonus.c ./src_bonus/set_pathfinder_bonus.c  ./src_bonus/execute_bonus.c \
					./src_bonus/set_here_doc_bonus.c ./src_bonus/set_arg_parser_bonus.c ./src_bonus/get_next_line_bonus.c

UTILS			=	./utils/ft_strchr.c ./utils/ft_strdup.c ./utils/ft_strjoin.c ./utils/ft_strlen.c \
					./utils/ft_substr.c ./utils/ft_calloc.c ./utils/ft_strlcpy.c ./utils/ft_bzero.c \
					./utils/ft_strncmp.c ./utils/ft_split.c \

OBJ				=	$(SRC:.c=.o)

OBJ_UTILS		=	$(UTILS:.c=.o)

all: $(NAME)

.c.o:
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(HEADERS) $(OBJ) $(OBJ_UTILS)
	cc $(CFLAGS) -o $(NAME) $(OBJ) $(OBJ_UTILS)

clear: $(NAME) clean
	clear

clean:
	rm -f $(OBJ) $(OBJ_B) $(OBJ_UTILS)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re: fclean all

.PHONY: bonus all clean fclean re clear clear_bonus .c.o

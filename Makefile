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

NAME			=	pipex 

NAME_B			=	pipex_bonus

HEADERS			=	./headers/pipex.h ./headers/objects.h ./headers/utils.h 

HEADERS_BONUS	=	./headers/pipex_bonus.h ./headers/objects_bonus.h ./headers/utils.h 

CFLAGS			=	-Wall -Wextra -Werror

SRC				=	./src/pipex.c ./src/check_args.c ./src/finalize.c ./src/set_arg_parser.c \
					./src/set_cmds.c ./src/redirect.c ./src/set_processes.c \
					./src/initialize.c ./src/set_pathfinder.c  ./src/execute.c

SRC_B			=	./src_bonus/pipex_bonus.c ./src_bonus/check_args_bonus.c ./src_bonus/finalize_bonus.c \
					./src_bonus/set_cmds_bonus.c ./src_bonus/redirect_bonus.c ./src_bonus/set_processes_bonus.c \
					./src_bonus/initialize_bonus.c ./src_bonus/set_pathfinder_bonus.c  ./src_bonus/execute_bonus.c \
					./src_bonus/set_here_doc_bonus.c ./src_bonus/set_arg_parser_bonus.c ./src_bonus/get_next_line_bonus.c

UTILS			=	./utils/ft_itoa.c ./utils/ft_itohex.c ./utils/ft_printf.c ./utils/ft_putchar_fd.c \
					./utils/ft_strchr.c ./utils/ft_strdup.c ./utils/ft_strjoin.c ./utils/ft_strlen.c \
					./utils/ft_toupper.c ./utils/ft_utoa.c 	./utils/ft_putstr_fd.c ./utils/ft_split.c \
					./utils/ft_substr.c ./utils/ft_calloc.c ./utils/ft_strlcpy.c ./utils/ft_bzero.c \
					./utils/ft_strncmp.c

OBJ				=	$(SRC:.c=.o)

OBJ_B			=	$(SRC_B:.c=.o)

OBJ_UTILS		=	$(UTILS:.c=.o)

all: $(NAME)

bonus: $(NAME_B)

.c.o:
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(HEADERS) $(OBJ) $(OBJ_UTILS)
	cc $(CFLAGS) -o $(NAME) $(OBJ) $(OBJ_UTILS)

$(NAME_B): $(HEADERS_BONUS) $(OBJ_B) $(OBJ_UTILS)
	cc $(CFLAGS) -o $(NAME_B) $(OBJ_B) $(OBJ_UTILS)

clear: $(NAME) clean
	clear

clear_bonus: $(NAME_B) clean
	clear

clean:
	rm -f $(OBJ) $(OBJ_B) $(OBJ_UTILS)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re: fclean all

.PHONY: bonus all clean fclean re clear clear_bonus .c.o

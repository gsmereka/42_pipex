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


HEADERS			=	./headers/pipex.h ./headers/objects.h ./headers/utils.h 

CFLAGS			=	-Wall -Wextra -Werror

OBJ_DIR			= 	./obj

SRC_DIR			=	/src

UTILS_DIR		=	/utils

SRC				=	pipex.c check_args.c finalize.c \
					set_cmds.c redirect.c set_processes.c \
					initialize.c set_pathfinder.c  execute.c \
					set_here_doc.c set_arg_parser.c get_next_line.c

UTILS			=	ft_strchr.c ft_strdup.c ft_strjoin.c ft_strlen.c \
					ft_substr.c ft_calloc.c ft_strlcpy.c ft_bzero.c \
					ft_strncmp.c ft_split.c \

OBJ				=	$(addprefix $(OBJ_DIR), $(addprefix $(SRC_DIR)/, $(SRC:.c=.o)))

OBJ_UTILS		=	$(addprefix $(OBJ_DIR), $(addprefix $(UTILS_DIR)/, $(UTILS:.c=.o)))

all: $(NAME)

$(OBJ_DIR)/%o : %c
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)$(SRC_DIR) $(OBJ_DIR)$(UTILS_DIR) 
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(HEADERS) $(OBJ) $(OBJ_UTILS)
	cc $(CFLAGS) -o $(NAME) $(OBJ) $(OBJ_UTILS)

clear: $(NAME) clean
	clear

clean:
	rm -rf $(OBJ) $(OBJ_B) $(OBJ_UTILS) $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re: fclean all

.PHONY: bonus all clean fclean re clear clear .c.o

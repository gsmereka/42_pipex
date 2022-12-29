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

OBJ_DIR			= 	./obj

SRC_DIR			=	/src_bonus

UTILS_DIR		=	/utils

SRC				=	pipex_bonus.c check_args_bonus.c finalize_bonus.c \
					set_cmds_bonus.c redirect_bonus.c set_processes_bonus.c \
					initialize_bonus.c set_pathfinder_bonus.c  execute_bonus.c \
					set_here_doc_bonus.c set_arg_parser_bonus.c get_next_line_bonus.c

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

.PHONY: bonus all clean fclean re clear clear_bonus .c.o

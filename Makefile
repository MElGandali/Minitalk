# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mel-gand <mel-gand@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/04 19:34:47 by mel-gand          #+#    #+#              #
#    Updated: 2023/02/04 19:34:56 by mel-gand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PROGRAM_SERVER = server
PROGRAM_CLIENT = client
PROGRAM_SERVER_B = server_bonus
PROGRAM_CLIENT_B = client_bonus
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
SRC_SERVER = ft_server.c
SRC_CLIENT = ft_client.c ft_atoi.c
SRC_CLIENT_BONUS = ft_client_bonus.c ft_atoi.c ft_strlen.c
SRC_SERVER_BONUS = ft_server_bonus.c ft_memset.c ft_server_bonus_utils.c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_CLIENT_BONUS = $(SRC_CLIENT_BONUS:.c=.o)
OBJ_SERVER_BONUS = $(SRC_SERVER_BONUS:.c=.o)

all: $(PROGRAM_SERVER) $(PROGRAM_CLIENT)

$(PROGRAM_SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(PROGRAM_SERVER)

$(PROGRAM_CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(PROGRAM_CLIENT)

bonus : $(PROGRAM_SERVER_B) $(PROGRAM_CLIENT_B)

$(PROGRAM_SERVER_B): $(OBJ_SERVER_BONUS)
	$(CC) $(CFLAGS) $(OBJ_SERVER_BONUS) -o $(PROGRAM_SERVER_B)
$(PROGRAM_CLIENT_B): $(OBJ_CLIENT_BONUS)
	$(CC) $(CFLAGS) $(OBJ_CLIENT_BONUS) -o $(PROGRAM_CLIENT_B)
%.o:%.c minitalk.h
	@$(CC) -c $< -o $@

clean:
	@$(RM) $(OBJ_SERVER) $(OBJ_CLIENT) $(OBJ_SERVER_BONUS) $(OBJ_CLIENT_BONUS)
fclean: clean
	@$(RM) $(PROGRAM_SERVER) $(PROGRAM_CLIENT) $(PROGRAM_SERVER_B) $(PROGRAM_CLIENT_B)
re: fclean all

.PHONY: all clean re




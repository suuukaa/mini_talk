# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-bouy <sel-bouy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 13:03:25 by sel-bouy          #+#    #+#              #
#    Updated: 2024/03/24 20:48:33 by sel-bouy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

CLIENT_NAME = client
SERVER_NAME = server

CLIENT_NAME_BONUS = client_bonus
SERVER_NAME_BONUS = server_bonus

SRC_CLIENT = client.c functions.c
SRC_SERVER = server.c functions.c

SRC_CLIENT_BONUS = client_bonus.c functions.c
SRC_SERVER_BONUS = server_bonus.c functions.c

all : $(CLIENT_NAME) $(SERVER_NAME)

bonus : client_bonus server_bonus

$(CLIENT_NAME) : $(SRC_CLIENT) library.h
	$(CC) $(CFLAGS) -o $(CLIENT_NAME) $(SRC_CLIENT)

$(SERVER_NAME) : $(SRC_SERVER) library.h
	$(CC) $(CFLAGS) -o $(SERVER_NAME) $(SRC_SERVER)

$(SERVER_NAME_BONUS) : $(SRC_SERVER_BONUS) library.h
	$(CC) $(CFLAGS) -o $(SERVER_NAME_BONUS) $(SRC_SERVER_BONUS)

$(CLIENT_NAME_BONUS) : $(SRC_CLIENT_BONUS) library.h
	$(CC) $(CFLAGS) -o $(CLIENT_NAME_BONUS) $(SRC_CLIENT_BONUS)

clean :
	rm -f $(CLIENT_NAME) $(SERVER_NAME)

fclean : clean

re : fclean all
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 10:44:16 by ibouhiri          #+#    #+#              #
#    Updated: 2020/01/10 11:16:16 by ibouhiri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGE = -lmlx -framework opengl -framework appkit
SRC = $(wildcard *.c)
EXEC = Cub3D

all :
	$(CC) -o $(EXEC) $(FLAGE) $(SRC) && ./$(EXEC) map.cub

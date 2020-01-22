# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibouhiri <ibouhiri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/09 10:44:16 by ibouhiri          #+#    #+#              #
#    Updated: 2020/01/22 12:24:24 by ibouhiri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc -lmlx -framework opengl -framework appkit
SRC = $(wildcard *.c)
EXEC = Cub3D

all :
	$(CC) -o $(EXEC) $(FLAGE) $(SRC) && ./$(EXEC) map.cub --save
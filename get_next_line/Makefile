# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjolliet <sjolliet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/22 14:53:25 by sjolliet          #+#    #+#              #
#    Updated: 2025/10/28 14:43:20 by sjolliet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=10
SRCS = get_next_line.c get_next_line_utils.c

# **************************************************************************** #

all: test

clean:
	rm -f ./test
	@echo "🧹 Test removed."

test:
	@$(CC) $(CFLAGS) main.c $(SRCS) -o $@
	@echo "🧪 Test created."

fclean: clean

.PHONY: all clean test
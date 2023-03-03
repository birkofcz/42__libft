# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbenes <sbenes@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 11:19:08 by sbenes            #+#    #+#              #
#    Updated: 2023/02/05 12:47:48 by sbenes           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC			= $(wildcard ft*.c)
OBJ			= $(SRC:.c=.o)
CC			= cc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
NAME		= libft.a

all:		$(NAME)

$(NAME):	$(OBJ)
			ar rcs $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ) 

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

bonus:		$(OBJ)
			ar rcs $(NAME) $(OBJ)


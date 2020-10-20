# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lweglarz <lweglarz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/15 14:17:23 by lweglarz          #+#    #+#              #
#    Updated: 2020/10/20 13:56:34 by lweglarz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minirt.a

FLAGS= -Wall -Wextra -Werror

SRCS= srcs/ft_split.c srcs/get_next_line.c srcs/get_scene_elements.c srcs/get_scene_objects.c srcs/parser.c srcs/utils.c

RM	= rm -f

OBJS = $(SRCS:.c=.o)

.c.o:
	cc $(FLAGS) -c $< -o $@
all: $(NAME)

$(NAME): $(OBJS) includes/minirt.h

	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
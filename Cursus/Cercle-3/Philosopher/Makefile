# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 10:26:59 by ttas              #+#    #+#              #
#    Updated: 2025/01/07 09:40:34 by ttas             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE = philosopher

# Files
SRC =			./srcs/main.c \
				

SRCS_INIT =		./srcs/Init/Init_Philosopher.c \
				

SRCS_UTILS =	./srcs/Utils/Error.c \
				./srcs/Utils/libft.c \
				./srcs/Utils/Debug.c
				
SRCS_Mutex =	./srcs/Mutex/Eating.c \
				./srcs/Mutex/Fork.c \
				
				
SRCS_PHILO =	./srcs/Philo/State.c \
				
				

SOURCES =		${SRC} ${SRCS_INIT} ${SRCS_UTILS} ${SRCS_STATE}
OBJECTS =		${SOURCES:.c=.o}

# Variables
CC = cc
# 
CFLAGS = -Wall -Werror -Wextra -Includes -fsanitize=thread -g
RM = rm -f

# Makefile
%.o:		%.c
		${CC} ${CFLAGS} -c $? -o $@

all:		${EXE}

${EXE}:		${OBJECTS} 
		@${CC} ${CFLAGS} ${OBJECTS} -o ${EXE}

ac: all clean

clean:
		@${RM} ${OBJECTS}

fclean:		clean
		@${RM} ${EXE}

re:			fclean all

.PHONY: all clean fclean re ac
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clai-ton <clai-ton@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/19 10:28:49 by ttas              #+#    #+#              #
#    Updated: 2025/01/23 15:00:19 by clai-ton         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program Executable
EXE = Executor
PARSE = parse.exe

# Files
SRC =			./srcs/main_exe.c

SRCS_INIT =		./srcs/Init/Init.c

#SRCS_PIPEX =	

SRCS_PARSE = 	./srcs/main_parser.c \
				./srcs/lexer/incorrect_quotes.c

EXE_SOURCES =		${SRC} ${SRCS_INIT}
PARSE_SOURCES =		${SRCS_PARSE}
EXE_OBJECTS =		${EXE_SOURCES:.c=.o}
PARSE_OBJECTS =		${PARSE_SOURCES:.c=.o}
LIBFT = ./Includes/libft

# Variables
CC = cc
RM = rm -f
# 
CFLAGS = -Wall -Werror -Wextra -Includes
CLEAKS = -fsanitize=address -g 

# Makefile
%.o:		%.c
		${CC} ${CFLAGS} -c $? -o $@

all:		${EXE}

${EXE}:		${EXE_OBJECTS} 
		@${MAKE} --silent -C ${LIBFT}
		@${CC} ${CFLAGS} ${CLEAKS} ${EXE_OBJECTS} ./Includes/libft/libft.a -lreadline -o $@

${PARSE}:		${PARSE_OBJECTS}
		@${MAKE} --silent -C ${LIBFT}
		@${CC} ${CFLAGS} ${PARSE_OBJECTS} ./Includes/libft/libft.a -lreadline -o $@

ac: all clean

clean:
		@${MAKE} --silent -C ${LIBFT} clean
		@${RM} ${EXE_OBJECTS} ${PARSE_OBJECTS}

fclean:		clean
		@${MAKE} --silent -C ${LIBFT} fclean
		@${RM} ${EXE} ${PARSE}

re:			fclean all

.PHONY: all clean fclean re ac
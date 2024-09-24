/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   So_Long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:39:43 by ttas              #+#    #+#             */
/*   Updated: 2024/09/12 09:41:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./gnl/get_next_line.h"
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../minilibx-linux/mlx.h"

// Valid Return
# define VALID 1
# define VALID_MAP_SIZE 2
# define VALID_MAP_COLLECTIBLES 3
# define VALID_MAP_FLOODFILL 4
# define VALID_MAP_CHAR 5
# define VALID_MAP_CLOSE 6
# define VALID_MAP_PLAYER 7
# define VALID_MAP_EXIT 8

// Error Handling
# define INVALID 0
# define INVALID_INPUT -1
# define INVALID_MAP_SIZE -2
# define INVALID_MAP_EXIT -3
# define INVALID_MAP_PLAYER -4
# define INVALID_MAP_COLLECTIBLES -5
# define INVALID_MAP_PATH -6
# define INVALID_MAP_CLOSE -7
# define INVALID_MAP_CHAR -8

// Jeu
# define PIX 16
# define ESC 0
# define UP 0
# define DOWN 0
# define LEFT 0
# define RIGHT 0

// Others
# define ERROR_FD 1

// Wall
# define WALL_FACE_TOP
# define WALL_FACE_BOTTOM
# define WALL_FACE_LEFT
# define WALL_FACE_RIGHT
# define WALL_FACE_TOP_LEFT
# define WALL_FACE_TOP_RIGHT
# define WALL_FACE_BOTTOM_LEFT
# define WALL_FACE_BOTTOM_RIGHT
# define WALL_FACE_TOP_BOTTOM
# define WALL_FACE_LEFT_RIGHT
# define WALL_FACE_TOP_LEFT_RIGHT
# define WALL_FACE_TOP_RIGHT_BOTTOM
# define WALL_FACE_TOP_BOTTOM_LEFT
# define WALL_FACE_BOTTOM_LEFT_RIGHT
# define WALL_FACE_ALL
# define WALL_FACE_NONE

// Struct
typedef enum e_bool
{
	false = 0,
	true = 1
}					t_bool;

typedef struct s_pos
{
	unsigned int	x;
	unsigned int	y;
}					t_pos;

typedef struct s_character
{
	struct s_pos	*pos;
	int 			dir;
	int 			state;
	void			*img;

}					t_character;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				line_length;
	int				endian;
}					t_mlx;

typedef struct s_map
{
	int 			fd_map;
	unsigned int	x;
	unsigned int	y;
	unsigned int 	coins;
	t_pos			*exit;
	t_character		*player;
	t_character		*ghost1;
	t_character		*ghost2;
	t_character		*ghost3;
	char 			**map;
	char 			**floodfill;
	t_mlx			*mlx;
}					t_map;


// INIT
int					init_map(char **argv, t_map *map);
int 				init_map_collectibles(t_map *map);
int 				init_map_char_player(t_map *map);
int					init_map_char_exit(t_map *map);

// PARSING
int					parsing_map_size(char **argv, t_map *map);
int 				parsing_map_init(char **argv, t_map *map);
int 				parsing_map_closed(t_map *map);
int 				parsing_map_char(t_map *map);
int 				parsing_map_char_player(t_map *map);
int 				parsing_map_char_exit(t_map *map);


// ERROR
void				error_message(int error);

// UTILS

#endif

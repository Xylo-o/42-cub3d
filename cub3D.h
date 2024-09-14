/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adprzyby <adprzyby@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:25:34 by adprzyby          #+#    #+#             */
/*   Updated: 2024/09/14 14:37:30 by adprzyby         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "Libft/libft.h"
# include "MLX/MLX42.h"
# include "get_next_line/get_next_line.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

#endif

#define mapWidth 24
#define mapHeight 24
#define tex_width 64
#define tex_height 64
#define screen_h 1200
#define screen_w 1600

typedef struct s_view
{
	double			cam_x;
	double			cam_y;
	double			dir_x;
	double			dir_y;
	double			pos_x;
	double			pos_y;
	int				step_x;
	int				step_y;
}					t_view;

typedef struct s_map
{
	int				map_x;
	int				map_y;
	int				side;
	int				hit;
}					t_map;

typedef struct s_ray
{
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			dist;
	double			dir_x;
	double			dir_y;
	double			x_zero;
	double			x_max;
	double			y_zero;
	double			y_max;
}					t_ray;

typedef struct s_paths
{
	char			*no_path;
	char			*so_path;
	char			*we_path;
	char			*ea_path;
}					t_paths;

typedef struct s_textures
{
	mlx_texture_t	*no_texture;
	mlx_texture_t	*so_texture;
	mlx_texture_t	*we_texture;
	mlx_texture_t	*ea_texture;
	mlx_texture_t	*tmp;
	uint32_t		*color;
	long			ceiling_color;
	long			floor_color;
	double			wall_x;
	int				x_tex;
	int				y_tex;
}					t_textures;

typedef struct s_game
{
	void			*mlx;
	void			*win;
	t_view			*view;
	t_map			*map;
	t_ray			*ray;
	t_paths			*paths;
	t_textures		*textures;
	mlx_image_t		*buffer;
}					t_game;

// CONTROLS
void				key_binds(void *param);
void				case_esc(t_game *game);
void				case_key_back(t_game *game, double mv_speed);
void				case_key_forward(t_game *game, double mv_speed);
void				case_key_rot_left(t_game *game, double rot_speed,
						double old_dir_x, double old_cam_x);
void				case_key_rot_right(t_game *game, double rot_speed,
						double old_dir_x, double old_cam_x);
void 				case_key_left(t_game *game, double mv_speed);
void 				case_key_right(t_game *game, double mv_speed);

// INIT
void				init_view(t_view *view);
void				init_ray(t_ray *ray);
void				init_map(t_map *map);
void				load_textures(t_game *game);
int					init(t_game *game);

// RENDER
void				render_structures(t_game *game);
void				draw_ceiling(t_game *game, int x, int draw_start);
void				draw_floor(t_game *game, int x, int draw_end);
void				put_image(t_game *game);
void				draw_walls(t_game *game, int x, int draw_start, int draw_end, int wall_height);
void				calculate_cam(t_game *game, int x);
void				calculate_delta(t_game *game);
void				calculate_pos(t_game *game);
void				calculate_hit(t_game *game);
void				calculate_ray(t_game *game);
int					calculate_draw_end(int wall_height);
int					calculate_draw_start(int wall_height);

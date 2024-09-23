/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgeiger <sgeiger@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:44:28 by adprzyby          #+#    #+#             */
/*   Updated: 2024/09/23 17:24:24 by sgeiger          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3D.h"

extern int 		worldMap[][mapHeight];

#define FLOOR_COLOR 0x00FF00FF
#define	CEILING_COLOR 0X0000FFFF

void	render_structures(t_game *game)
{
	int		wall_height;
	int		draw_start;
	int		draw_end;
	int		x;

	x = 0;
	while (x < screen_w)
	{
		calculate_cam(game, x);
		calculate_delta(game);
		game->map->hit = 0;
		calculate_pos(game);
		calculate_hit(game);
		calculate_ray(game);
		wall_height = (int)(screen_h / game->ray->dist);
		draw_start = calculate_draw_start(wall_height);
		draw_end = calculate_draw_end(wall_height);
		draw_ceiling(game, x, draw_start);
		draw_walls(game, x, draw_start, draw_end);
		draw_floor(game, x, draw_end);
		x++;
	}
}

void	put_image(t_game *game)
{
	mlx_delete_image(game->mlx, game->buffer);
	game->buffer = mlx_new_image(game->mlx, screen_w, screen_h);
	render_structures(game);
	mlx_image_to_window(game->mlx, game->buffer, 0, 0);
}

void	draw_walls(t_game *game, int x, int draw_start, int draw_end)
{
	int	y;

	y = draw_start;
	while (y < draw_end)
	{
		get_texture(game, x, y);
		mlx_put_pixel(game->buffer, x, y, game->map->color);
		y++;
	}
}

void	draw_ceiling(t_game *game, int x, int draw_start)
{
	int	y;

	y = 0;
	while (y < draw_start)
	{
		mlx_put_pixel(game->buffer, x, y, CEILING_COLOR);
		y++;
	}
}

void	draw_floor(t_game *game, int x, int draw_end)
{
	int	y;

	y = draw_end + 1;
	while (y < screen_h)
	{
		mlx_put_pixel(game->buffer, x, y, FLOOR_COLOR);
		y++;
	}
}

uint32_t texture[4][tex_width * tex_height];


// void render_structures(t_game *game)
// {
// 	// uint32_t texture[0] = ;

//     for (int x = 0; x < screen_w; x++)
//     {
//         // calculate ray position and direction
//         double cameraX = 2 * x / (double)screen_w - 1; // x-coordinate in camera space
//         double rayDirX = dirX + planeX * cameraX;
//         double rayDirY = dirY + planeY * cameraX;

//         // which box of the map we're in
//         int mapX = (int)posX;
//         int mapY = (int)posY;

//         // length of ray from current position to next x or y-side
//         double sideDistX;
//         double sideDistY;

//         // length of ray from one x or y-side to next x or y-side
//         double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
//         double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
//         double perpWallDist;

//         // what direction to step in x or y-direction (either +1 or -1)
//         int stepX;
//         int stepY;

//         int hit = 0; // was there a wall hit?
//         int side;    // was a NS or a EW wall hit?

//         // calculate step and initial sideDist
//         if (rayDirX < 0)
//         {
//             stepX = -1;
//             sideDistX = (posX - mapX) * deltaDistX;
//         }
//         else
//         {
//             stepX = 1;
//             sideDistX = (mapX + 1.0 - posX) * deltaDistX;
//         }
//         if (rayDirY < 0)
//         {
//             stepY = -1;
//             sideDistY = (posY - mapY) * deltaDistY;
//         }
//         else
//         {
//             stepY = 1;
//             sideDistY = (mapY + 1.0 - posY) * deltaDistY;
//         }

//         // perform DDA
//         while (hit == 0)
//         {
//             // jump to next map square, either in x-direction, or in y-direction
//             if (sideDistX < sideDistY)
//             {
//                 sideDistX += deltaDistX;
//                 mapX += stepX;
//                 side = 0;
//             }
//             else
//             {
//                 sideDistY += deltaDistY;
//                 mapY += stepY;
//                 side = 1;
//             }
//             // check if ray has hit a wall
//             if (worldMap[mapX][mapY] > 0)
//                 hit = 1;
//         }

//         // calculate distance of perpendicular ray (Euclidean distance would give fisheye effect!)
//         if (side == 0)
//             perpWallDist = (sideDistX - deltaDistX);
//         else
//             perpWallDist = (sideDistY - deltaDistY);

//         // calculate height of line to draw on screen
//         int lineHeight = (int)(screen_h / perpWallDist);

//         // calculate lowest and highest pixel to fill in current stripe
//         int drawStart = -lineHeight / 2 + screen_h / 2;
//         if (drawStart < 0)
//             drawStart = 0;
//         int drawEnd = lineHeight / 2 + screen_h / 2;
//         if (drawEnd >= screen_h)
//             drawEnd = screen_h - 1;

//         // texturing calculations
//         int texNum = worldMap[mapX][mapY] - 1; // 1 subtracted from it so that texture 0 can be used!

//         // calculate value of wallX
//         double wallX; // where exactly the wall was hit
//         if (side == 0)
//             wallX = posY + perpWallDist * rayDirY;
//         else
//             wallX = posX + perpWallDist * rayDirX;
//         wallX -= floor((wallX));

//         // x coordinate on the texture
//         int texX = (int)(wallX * (double)tex_width);
//         if (side == 0 && rayDirX > 0)
//             texX = tex_width - texX - 1;
//         if (side == 1 && rayDirY < 0)
//             texX = tex_width - texX - 1;

//         // How much to increase the texture coordinate per screen pixel
//         double step = 1.0 * tex_height / lineHeight;
//         // Starting texture coordinate
//         double texPos = (drawStart - screen_h / 2 + lineHeight / 2) * step;
//         for (int y = drawStart; y < drawEnd; y++)
//         {
//             // Cast the texture coordinate to integer, and mask with (tex_height - 1) in case of overflow
//             int texY = (int)texPos & (tex_height - 1);
//             texPos += step;
//             uint32_t color = texture[0][tex_height * texY + texX];
//             // make color darker for y-sides: R, G and B byte each divided through two with a "shift" and an "and"
//             if (side == 1)
//                 color = (color >> 1) & 8355711;
//             // Draw pixel to the MLX42 image
//             mlx_put_pixel(image, x, y, color);
//         }
//     }
// }

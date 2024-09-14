#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "MLX/MLX42.h"

#define WIDTH 800
#define HEIGHT 600
#define MAP_WIDTH 10
#define MAP_HEIGHT 10
#define TEXTURE_WIDTH 64
#define TEXTURE_HEIGHT 64

int worldMap[MAP_WIDTH][MAP_HEIGHT] =
{
    {1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,0,0,0,0,0,0,0,0,1},
    {1,1,1,1,1,1,1,1,1,1}
};

// Texture arrays to store the image data
mlx_texture_t* texture[4];

typedef struct s_game {
    mlx_t* mlx;
    double posX, posY;       // Player position
    double dirX, dirY;       // Player direction
    double planeX, planeY;   // Camera plane
} t_game;

void draw_vertical_line(mlx_image_t* img, int x, int start, int end, uint32_t color) {
    for (int y = start; y < end; y++) {
        mlx_put_pixel(img, x, y, color);
    }
}

void load_textures() {
    texture[0] = mlx_load_png("textures/pics/bluestone.png");
    texture[1] = mlx_load_png("textures/pics/colorstone.png");
    texture[2] = mlx_load_png("textures/pics/greystone.png");
    texture[3] = mlx_load_png("textures/pics/redbrick.png");

    for (int i = 0; i < 4; i++) {
        if (!texture[i]) {
            printf("Error loading texture %d\n", i);
            exit(EXIT_FAILURE);
        }
    }
}

void render(t_game* game, mlx_image_t* img) {
    for (int x = 0; x < WIDTH; x++) {
        // Calculate ray position and direction
        double cameraX = 2 * x / (double)WIDTH - 1;
        double rayDirX = game->dirX + game->planeX * cameraX;
        double rayDirY = game->dirY + game->planeY * cameraX;

        // Map position
        int mapX = (int)game->posX;
        int mapY = (int)game->posY;

        // Length of ray from one x or y-side to next x or y-side
        double sideDistX, sideDistY;

        // Length of ray from one x or y-side to next x or y-side
        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);
        double perpWallDist;

        // Direction to go in x and y (+1 or -1)
        int stepX, stepY;
        int hit = 0; // was there a wall hit?
        int side; // was the wall hit vertical or horizontal?

        // Calculate step and initial sideDist
        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (game->posX - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - game->posX) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (game->posY - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - game->posY) * deltaDistY;
        }

        // Perform DDA
        while (hit == 0) {
            // Jump to next map square, OR in x-direction, OR in y-direction
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            // Check if ray has hit a wall
            if (worldMap[mapX][mapY] > 0) hit = 1;
        }

        // Calculate distance to the point of impact
        if (side == 0)
            perpWallDist = (mapX - game->posX + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - game->posY + (1 - stepY) / 2) / rayDirY;

        // Calculate height of line to draw on screen
        int lineHeight = (int)(HEIGHT / perpWallDist);

        // Calculate lowest and highest pixel to fill in current stripe
        int drawStart = -lineHeight / 2 + HEIGHT / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + HEIGHT / 2;
        if (drawEnd >= HEIGHT) drawEnd = HEIGHT - 1;

        // Choose texture for the current wall
        mlx_texture_t* tex;
        if (side == 0 && rayDirX > 0) tex = texture[0]; // North
        else if (side == 0 && rayDirX < 0) tex = texture[1]; // South
        else if (side == 1 && rayDirY > 0) tex = texture[2]; // West
        else tex = texture[3]; // East

        // Calculate x coordinate on the texture
        double wallX; // Where exactly the wall was hit
        if (side == 0) wallX = game->posY + perpWallDist * rayDirY;
        else wallX = game->posX + perpWallDist * rayDirX;
        wallX -= floor(wallX);

        // x coordinate on the texture
        int texX = (int)(wallX * (double)TEXTURE_WIDTH);
        if (side == 0 && rayDirX > 0) texX = TEXTURE_WIDTH - texX - 1;
        if (side == 1 && rayDirY < 0) texX = TEXTURE_WIDTH - texX - 1;

        // Draw the vertical stripe of the texture onto the wall
        for (int y = drawStart; y < drawEnd; y++) {
            int texY = (((y * 256 - HEIGHT * 128 + lineHeight * 128) * TEXTURE_HEIGHT) / lineHeight) / 256;
            uint32_t color = *(uint32_t*)(tex->pixels + (texY * TEXTURE_WIDTH + texX) * sizeof(uint32_t));
            mlx_put_pixel(img, x, y, color);
        }
    }
}

void update(void* param) {
    t_game* game = (t_game*)param;
    mlx_image_t* img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
    render(game, img);
    mlx_image_to_window(game->mlx, img, 0, 0);
}

int main() {
    t_game game;
    game.mlx = mlx_init(WIDTH, HEIGHT, "Raycasting with Textures", false);
    game.posX = 5;
    game.posY = 5;
    game.dirX = -1;
    game.dirY = 0;
    game.planeX = 0;
    game.planeY = 0.66;

    load_textures();

    mlx_loop_hook(game.mlx, update, &game);
    mlx_loop(game.mlx);

    for (int i = 0; i < 4; i++) {
        mlx_delete_texture(texture[i]);
    }
    mlx_terminate(game.mlx);
    return 0;
}

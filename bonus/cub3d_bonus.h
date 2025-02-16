/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aragragu <aragragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 17:43:37 by aragragu          #+#    #+#             */
/*   Updated: 2025/02/16 20:42:06 by aragragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
#define CUB3D_H

#include "../mlx_linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
# include <limits.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

enum
{
    FREE,
    ALLOC,
};
     
#define CELL_SIZE 32          // Map tile size
#define FOV 0.90               // Field of view

#define W_KEY 119          // W key for forward
#define A_KEY 97           // A key for strafe left
#define S_KEY 115          // S key for backward
#define D_KEY 100          // D key for strafe right
#define LEFT_KEY 65361     // Left arrow key for rotating left
#define RIGHT_KEY 65363    // Right arrow key for rotating right
#define ESCAPE_KEY 65307   // Escape key

// #define W_KEY 13          // W key for forward (macOS)
// #define A_KEY 0           // A key for strafe left (macOS)
// #define S_KEY 1           // S key for backward (macOS)
// #define D_KEY 2           // D key for strafe right (macOS)
// #define LEFT_KEY 123      // Left arrow key for rotating left (macOS)
// #define RIGHT_KEY 124     // Right arrow key for rotating right (macOS)
// #define ESCAPE_KEY 53     // Escape key (macOS)
#define MOVE_SPEED 4
#define ROT_SPEED 0.06
#define HITBOX_MARG 0.2
#define PI 3.141592653589793
#define MAP_WIDTH 2000
#define MAP_HEIGHT 1500
#define MINIMAP_CENTER_X 100
#define MINIMAP_CENTER_Y 100
#define MINIMAP_TILE_SIZE 10

#define MINIMAP_RADIUS 100
#define MINIMAP_WIDTH 200
#define MINIMAP_HEIGHT 200
#define MINIMAP_SCALE 4
#define TRAIL_MAX_SIZE 100 
#define MINIMAP_FRAME_COLOR 0xFFD700 

typedef struct s_player_trail
{
    int x[TRAIL_MAX_SIZE];
    int y[TRAIL_MAX_SIZE];
    int size;
} t_player_trail;

typedef struct s_player
{
    double x;
	double y;
    double dir_x;
	double dir_y;
    double plane_x;
	double plane_y;
    int forward;
    int backward;
    int left;
    int right;
    int rotate_left;
    int rotate_right;
    double move_speed;
    double rot_speed;
    int first_time;
    int prev_x;
    int door_open;
} t_player;

typedef struct s_map
{
    char **grid;
    int width;
	int height;
} t_map;


typedef struct s_free
{
    void    *add;
    struct s_free   *next;
}               t_free;

typedef struct s_img
{
    void *img_ptr;
    unsigned char *data;
    int bpp;
    int size_line;
    int endian;
    int width;
    int height;
} t_img;

typedef struct s_ray
{
    double camera_x;
    double ray_dir_x;
    double ray_dir_y;
    int map_x;
    int map_y;
    double delta_dist_x;
    double delta_dist_y;
    double side_dist_x;
    double side_dist_y;
    double perp_wall_dist;
    int step_x;
    int step_y;
    int hit;
    int side;
    int line_height;
    int draw_start;
    int draw_end;
    int is_door;
} t_ray;

typedef struct s_minimap
{
    int start_x;
    int start_y;
    int end_x;
    int end_y;
} t_minimap;

typedef struct s_ceil_floor
{
    double ray_dir_x0;
    double ray_dir_y0;
    double ray_dir_x1;
    double ray_dir_y1;
    double floor_step_x;
    double floor_step_y;
    double floor_x;
    double floor_y;
} t_ceil_floor;


typedef struct s_textures
{
    void    *image;
    void    *add;
    int     width;
    int     height;
    int     bp_pixels;
    int     l_length;
    int     endian; 
} t_textures;

typedef struct s_game
{
	char	*norh;
	char	*west;
	char	*east;
	char	*south;
	char	*floor;
	char	*ceiling;
    unsigned int    c_floor;
    unsigned int    c_ceiling;
    int             current_frame;
    double          last_frame_time;
    double          frame_delay;
    int             frame_counter;
    int             is_shooting;
    t_textures *gun[21];
    t_textures *image[5];

} t_game;


typedef struct s_parsing
{
	int			fd;
	int			file_lenght;
	int			map_start_index;
	char		**file_lines;
} t_parsing;

typedef struct s_data
{
    void *mlx;
    void *win;
    t_map map;
    t_player player;
    t_player_trail player_trail;
    t_minimap minimap;
    t_ceil_floor ceil_floor;
    t_ray ray;
    t_img img;
    t_game  game;
    t_parsing *info;
} t_data;

typedef struct s_cordinate
{
    int     y;
    int     color;
    int     tex_num;
    double  wall_x;
    int     tex_x;
    int     tex_y;
    double  tex_step;
    double  tex_pos;
}               t_cordinate;

typedef struct s_info
{
    int             x;
    int             y;
    int             j;
    int             dest_y;
    int             bpp_src;
    int             bpp_dst;
    char            *src_row;
    unsigned char   *dst_row;
}               t_info;

void map_init(t_map *map, const char *map_file);
void set_player_plane(t_player *player);
int find_player_position(t_map *map, t_player *player);
void data_init(t_data *data);
void	init_player_defaults(t_player *player);
void init_player_direction(t_player *player, char orientation);
void	init_player_trail(t_player_trail *trail);
void	init_map_and_player(t_data *data);
bool	is_player_cell(char cell);
void	set_player_direction(char cell, t_player *player);
void	set_direction(t_player *player, double dir_x, double dir_y);
int get_pixel_index(int x, int y, t_img *img);
void draw_pixel(t_img *img, int x, int y, int color);
void put_pixel_to_image(t_img *img, int x, int y, int color, int img_width, int img_height);
void calculate_line_steps(int x1, int y1, int x2, int y2, int *dx, int *dy, int *p);
int color_cell_matching(char cell);
void draw_line(t_img *img, int x1, int y1, int x2, int y2, int color);
void draw_rectangle(t_img *img, int x, int y, int width, int height, int color, int img_width, int img_height);
void render(t_data *data);
void map_free(t_map *map);
void raycast(t_data *data);
void render_minimap(t_data *data);
void draw_rectangle(t_img *img, int x, int y, int width, int height, int color, int img_width, int img_height);
void render_3d_view(t_data *data);
void render_ceiling_and_floor(t_data *data);
void draw_minimap_tiles(t_data *data);
void draw_player_on_minimap(t_data *data);
void calculate_viewport(t_data *data);
void render_ceiling_and_floor(t_data *data);
void initialize_ray(t_ray *ray, t_data *data, int x);
void	calculate_step_and_side_dist(t_ray *ray, t_data *data);
void	perform_dda(t_ray *ray, t_map *map, t_player *player);
void calculate_wall_distance(t_ray *ray, t_player *player);
void calculate_line_dimensions(t_ray *ray, int screen_height);
void draw_wall(t_ray *ray, t_data *data, int x);
void raycast(t_data *data);
int is_walkable(t_map *map, double x, double y);
void move_forward(t_player *player, t_map *map);
void move_backward(t_player *player, t_map *map);
void strafe_left(t_player *player, t_map *map);
void strafe_right(t_player *player, t_map *map);
void rotate_left(t_player *player);
void rotate_right(t_player *player);
void move_player(t_data *data);
void handle_key_press(int key, t_data *data);
void handle_key_press_rotation(int key, t_data *data);
int key_press(int key, t_data *data);
void handle_key_release(int key, t_data *data);
void handle_key_release_rotation(int key, t_data *data);
int key_release(int key, t_data *data);
void setup_mouse_rotation(t_data *data);
int mouse_press(int button, int x, int y, t_data *data);
void handle_door(t_ray *ray, t_data *data);
void quit(char *msg);
void ft_bzero(void *s, size_t n);
int game_loop(t_data *data);
void clear_img(t_data *data);
void clear_screen(t_data *data, int color);
void draw_vertical_line2(t_img *img, int x, t_ray *ray, int color);
void    *ft_malloc(int size, int status);
void    my_perror(int status, char *str);
int        ft_strncmp(const char *s1, const char *s2, int n);
int         ft_strlen(const char *str);
int        check_file(const char *argv);
void    file_parsing(t_data *data, char *str);
void    store_data(t_data *data, int fd);
char    *ft_strdup(char *s1);
char    *ft_strchr(const char *s, int c);
char    *ft_substr(char *s, unsigned int start, size_t len);
char    **ft_split(char const *s, char c);
char    *get_next_line(int fd);
char    *ft_strjoin(char *s1, char *s2);
void    fill_texture(char *str, char **texture, int *count);
int        file_lenght(char *str);
void    get_file_lines(char *str, t_parsing *info);
int        map_first_line_index(char **str);
void    parse_map(t_data *data);
void    check_rest(char    **str);
char    *ft_substr2(char *s, unsigned int start, size_t len);
void    *ft_calloc(size_t count, size_t size);
int        only_space(char *str);
int        ft_strlen2(char **str);
void    check_map_surrending(char **map);
void    free_str(char **str);
int        is_num(char *str);
int	    ft_atoi(const char *str, int *succes);
void     print_data(t_data *data);
void    check_inside_map(char **map);
void    check_texture(char *str, t_game *game, int *count);
void     print_2d_array(char **array);
char    *ft_strtrim(char const *s1, char const *set);
void    fill_color(char **str, char **texture, int *count);
int        is_num2(char *str);
void print_map(char **map);
char	*ft_strdup2(char *s1);
char	*ft_itoa(int nb);
int	is_map_line(char *str);
int	wrong_char(char c);
int	map_lenghttttttttttttt(t_data *data);
void	images_init(t_data *data);
void	free_textures(t_data *data);
void	colors_init(t_data *data);
void    load_gun_frames(t_data  *data);
void    render_gun_sprite(t_data *data);
void	check_player_surending(char **map);
int	check_surrending(char **str, int x, int y);

#endif
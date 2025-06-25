/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbenatar <lbenatar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:03:06 by vincent           #+#    #+#             */
/*   Updated: 2025/03/18 14:16:20 by lbenatar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../libft/libft.h"
# include "../mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <unistd.h>

# ifndef MAP_WIDTH
#  define MAP_WIDTH 1100
# endif

# ifndef MAP_HEIGHT
#  define MAP_HEIGHT 800
# endif

# ifndef SIZE_SQUARE
#  define SIZE_SQUARE 5
# endif

# define RESET "\e[0m"
# define GREEN "\e[32m"

# ifndef POV
#  define POV 70.0
# endif

# define M_PI 3.14159265358979323846

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
	char	*img_pixels_n;
	int		bits_per_pixel_n;
	int		endian_n;
	int		line_len_n;
	int		height_n;
	int		width_n;
	char	*img_pixels_s;
	int		bits_per_pixel_s;
	int		endian_s;
	int		line_len_s;
	int		height_s;
	int		width_s;
	char	*img_pixels_w;
	int		bits_per_pixel_w;
	int		endian_w;
	int		line_len_w;
	int		height_w;
	int		width_w;
	char	*img_pixels_e;
	int		bits_per_pixel_e;
	int		endian_e;
	int		line_len_e;
	int		height_e;
	int		width_e;
}			t_img;

typedef struct s_data
{
	int		ac;
	char	**av;
	char	*n_texture;
	char	*s_texture;
	char	*w_texture;
	char	*e_texture;
	void	*north;
	void	*east;
	void	*south;
	void	*west;
	int		direction;
	char	depart;
	void	*mlx_ptr;
	void	*win_ptr;
	char	**color_c;
	char	*ceiling;
	char	**color_f;
	char	*floor;
	char	*input_file;
	char	**input_tab2;
	char	**map;
	char	**big_map;
	int		map_width;
	int		map_height;
	int		x_start;
	int		y_start;
	double	x_perso;
	double	y_perso;
	double	x_test;
	double	y_test;
	double	tab_ray[MAP_WIDTH];
	double	y_ray_impact[MAP_WIDTH];
	double	x_ray_impact[MAP_WIDTH];
	double	tab_square_ray[MAP_WIDTH];
	double	tab_final_ray[MAP_WIDTH];
	double	pourcentage_tab[MAP_WIDTH];
	double	linear_tab_ray[MAP_WIDTH];
	double	tab_pos[MAP_WIDTH];
	char	tab_shap[MAP_WIDTH + 1];
	t_img	*img;
}			t_data;

void		fill_linear_pourcentage_tab(t_data *data);
bool		ft_parsing_color(t_data *data);
bool		only_1__0_or_space(char *line);
void		move_camera(t_data *data, int keysym);
void		move_perso(t_data *data, int keysym);
void		fill_linear_tab_ray(t_data *data);
bool		ft_init_struct(t_data *data);
bool		ft_doc_parsing(t_data *data);
void		get_big_map(t_data *data);
bool		start_game(t_data *data);
int			close_window(t_data *data);
bool		ft_lstinitgraph(t_data *data);
int			handle_input(int keysym, t_data *data);
void		ft_put_wall_1(char **map, t_data *data);
char		*get_dir_str(t_data *data, char a, char b);
char		*get_color_str(t_data *data, char c);
char		**ft_get_tab(char *fichier);
bool		texture_check(t_data *data);
bool		ft_map_close_check(t_data *data);
void		ft_get_start_position(t_data *data);
bool		ft_init_data_mlx(t_data *data);
bool		get_mlx_ptr(t_data *data);
char		**ft_get_map(char **tab);
bool		map_related_lines_all_together(char **tab);
bool		ft_parsing_map(t_data *data);
bool		ft_one_entry(char **map, t_data *data);
bool		ft_floodfill(t_data *data);
bool		ft_map_compact(char **map2);
void		my_pixel_put(t_img *img, int x, int y, int color);
void		correcting_data(char **tab);
char		**ft_get_square_map(char **map);
void		liberator_god(t_data *data);
void		screen_distance(t_data *data);
void		ft_printtab(char **tab);
double		get_rad(double angle);
double		get_pos(t_data *data, double direction, int i);
int			create_img(t_data *data);
void		update_img(t_data *data);
void		put_lines(t_data *data);
bool		only_1__0_or_space2(char *line);
bool		ft_malloc_texture_verif(t_data *data);
bool		verif_occurence_color_texture(t_data *data);
void		malloc_error(void);
bool		ft_get_color_format(t_data *data);
void		get_direction(t_data *data);
bool		init_t_img(t_data *data);
void		init_tab_ray(t_data *data);
int			ft_table_strdup_space2(char **dest, int j, char **src);
char		**ft_table_strdup_space(char **src);
bool		ft_map_close_check_verif(char **map2, int i, int j);
bool		ft_map_close_check(t_data *data);
void		replace_backslashn(char **map);
bool		only_1__0_or_space2(char *line);
bool		only_1__0_or_space(char *line);
bool		not_all_space(char *line);
int			count_map_related_lines(char **tab);
bool		ft_iswhite_space(char c);
bool		ft_texture_xpm_verif(char *path);
bool		ft_malloc_texture_verif(t_data *data);
bool		map_is_last(char **input);
double		ray_calculator_square(t_data *data, double angle, int i);
bool		is_wall(double x, double y, t_data *data);
double		get_rad(double angle);
int			close_window(t_data *data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:51:11 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/08 18:47:32 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <errno.h>

# define STDERR 2
# define Q_KEY 113
# define E_KEY 101
# define ESC_KEY 65307
# define PLUS_KEY 65451
# define MINUS_KEY 65453
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define UP_KEY 65362
# define DOWN_KEY 65364
# define ON_DESTROY 17

// Resolution of window
# define RESO_X 1200
# define RESO_Y 900
// 1-unit equal to x pixel
# define MAGNITUDE 20

// Store delta-x delta-y if we move x-unit in x, y or z direction
typedef struct s_delta
{
	double	delta_x;
	double	delta_y;
}	t_delta;

// Store delta-x delta-y if we move x-unit in anydirection
typedef struct s_vector
{
	t_delta	x;
	t_delta	y;
	t_delta	z;
}	t_vector;

// Store x,y,color coordinate
typedef struct s_coor
{
	int	x;
	int	y;
	int	c;
}	t_coor;

// Store coordinate and unit vector
typedef struct s_pen
{
	t_coor		coor;
	t_vector	unit;
}	t_pen;

// Store start & end coordinate of line
typedef struct s_line
{
	t_coor	start;
	t_coor	end;
}	t_line;

// Store file data
typedef struct s_data
{
	int		*color;
	int		*attribute;
	size_t	n_row;
	size_t	n_col;
}	t_data;

// Store perspectice such as angle of view, scale, picture offset
typedef struct s_view
{
	int		scale;
	int		angle;
	int		offset_x;
	int		offset_y;
	double	level;
}	t_view;

// Store image basic information ptr = start of image, bpp = byte per pixel
typedef struct s_img
{
	void	*mlx_img;
	char	*ptr;
	int		bpp;
	int		line;
	int		end;
}	t_img;

// Store information on displaying
typedef struct s_info
{
	void	*mlx;
	void	*window;
	t_img	*image;
	t_view	*view;
}	t_info;

// Store all information
typedef struct s_fdf
{
	t_info	*info;
	t_data	*data;
}	t_fdf;

// Free Process
void		free_data(t_data *data);
void		free_info(t_info *info);
void		free_array(char **array);

// Error Process
void		error_init(t_data *data, t_info *info);

// Event Process
int			hook_keydown_1(int key, t_fdf *fdf);
int			hook_mouse(int key, int x, int y, t_fdf *fdf);

// Drawing Process
void		draw_line(t_line line, t_img *img);
void		connect_x(t_img *img, t_pen pen, t_data *data, int i);
void		connect_y(t_img *img, t_pen pen, t_data *data, int i);

// Render Process
void		clear_image(t_img *image);
void		render(t_info *info, t_data *data);
void		draw_image(t_view *view, t_data *data, t_img *image);
void		image_put_pixel(t_img *image, int x, int y, int color);
t_img		*create_new_img(t_info *info);

// Coordinate Process
t_pen		init_pen(t_view *view);
t_pen		move_pen(t_pen pen, int move_x, int move_y);
t_coor		move_coor(t_pen pen, int x, int y, int z);

// Vector Process
t_vector	unit_vector(t_view *view);

// Parsing Process
void		parsing_file(char *file_path, t_data *data);

// Exit Process
int			close_fdf(t_fdf *fdf);

#endif

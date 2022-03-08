/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:51:11 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/08 16:59:53 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <errno.h>

# define STDERR 2
# define ESC_KEY 65307
# define PLUS_KEY 65451
# define MINUS_KEY 65453
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

// Store x,y,color coordinate
typedef struct s_coor
{
	int	x;
	int	y;
	int	c;
}	t_coor;

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
	int		angle_delta;
	int		project;
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
int			hook_keydown(int key, t_fdf *fdf);
int			hook_mouse(int key, int x, int y, t_fdf *fdf);

// Render Process
void		render(t_fdf *fdf);
void		draw_image(t_fdf *fdf);
void		clear_image(t_img *image);
void		image_put_pixel(t_img *image, int x, int y, int color);
t_img		*create_new_img(t_info *info);

// Parsing Process
void		parsing_file(char *file_path, t_data *data);

// Exit Process
int			close_fdf(t_fdf *fdf);

#endif

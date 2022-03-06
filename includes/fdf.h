/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:51:11 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/06 23:22:02 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <errno.h>

# define STDERR 2
# define RESO_X 1200
# define RESO_Y 900
# define INIT_X 300
# define INIT_Y 300
# define MAGNITUDE 10

typedef struct s_data
{
	int		*color;
	int		*attribute;
	size_t	n_row;
	size_t	n_col;
}	t_data;

typedef struct s_info
{
	int		angle_x;
	int		angle_y;
	int		zoom;
	void	*mlx;
	void	*window;
}	t_info;

void	free_data(t_data *data);
void	free_info(t_info *info);
void	free_array(char **array);
void	render(t_info *info, t_data *data);
void	error_init(t_data *data, t_info *info);
void	parsing_file(char *file_path, t_data *data);
void	draw_line_x(size_t index, t_data *data, t_info *info);
void	draw_line_y(size_t index, t_data *data, t_info *info);

#endif

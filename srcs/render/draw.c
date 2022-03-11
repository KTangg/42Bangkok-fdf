/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:02:29 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/11 15:09:05 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	draw_line(t_line line, t_img *img)
{
	int		i;
	int		delta_c;
	double	size;
	t_delta	delta;

	delta.delta_x = line.end.x - line.start.x;
	delta.delta_y = line.end.y - line.start.y;
	size = sqrt(pow(delta.delta_x, 2) + pow(delta.delta_y, 2));
	delta.delta_x = delta.delta_x / size;
	delta.delta_y = delta.delta_y / size;
	delta_c = (line.end.c - line.start.c) / size;
	i = 0;
	while (i < size)
	{
		if (line.start.x + round(delta.delta_x * i) < RESO_X
			&& line.start.x + round(delta.delta_x * i) > 0
			&& line.start.y + round(delta.delta_y * i) < RESO_Y
			&& line.start.y + round(delta.delta_y * i) > 0)
		{
			image_put_pixel(img, line.start.x + round(delta.delta_x * i),
				line.start.y + round(delta.delta_y * i),
				line.start.c + round(delta_c * i));
		}
		i++;
	}
}

void	connect_x(t_img *img, t_pen pen, t_data *data, int index)
{
	t_line	line;

	line.start = move_coor(pen, -data->n_col / 2,
			-data->n_row / 2, data->attribute[index]);
	line.start.c = data->color[index];
	line.end = move_coor(pen, -data->n_col / 2 + 1,
			-data->n_row / 2, data->attribute[index + 1]);
	line.end.c = data->color[index + 1];
	draw_line(line, img);
}

void	connect_y(t_img *img, t_pen pen, t_data *data, int i)
{
	t_line	line;

	line.start = move_coor(pen, -data->n_col / 2,
			-data->n_row / 2, data->attribute[i]);
	line.start.c = data->color[i];
	line.end = move_coor(pen, -data->n_col / 2,
			-data->n_row / 2 + 1, data->attribute[i + data->n_col]);
	line.end.c = data->color[i + data->n_col];
	draw_line(line, img);
}

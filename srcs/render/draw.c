/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:02:29 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/08 17:00:16 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <math.h>

static void	draw_line(t_line line, t_img *img)
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
		if (line.start.x + round(delta.delta_x * i) <= RESO_X
			&& line.start.x + round(delta.delta_x * i) >= 0
			&& line.start.y + round(delta.delta_y * i) <= RESO_Y
			&& line.start.y + round(delta.delta_y * i) >= 0)
		{
			image_put_pixel(img, line.start.x + round(delta.delta_x * i),
				line.start.y + round(delta.delta_y * i),
				line.start.c + round(delta_c * i));
		}
		i++;
	}
}

static void	connect_coor(t_fdf *fdf, t_coor c1, t_coor c2)
{
	size_t	i_c1;
	size_t	i_c2;
	t_data	*data;
	t_line	line;

	data = fdf->data;
	i_c1 = (data->n_col * c1.y) + c1.x;
	i_c2 = (data->n_col * c1.y) + c1.x;
	c1 = project(c1, data->attribute[i_c1], fdf->info->view);
	c2 = project(c2, data->attribute[i_c2], fdf->info->view);
	if (c1.c == 0)
		c1.c = data->color[i_c1];
	if (c2.c == 0)
		c2.c = data->color[i_c2];
	line = {c1, c2};
	draw_line(line, fdf->info->image);
}

void	draw_image(t_fdf *fdf)
{
	int			color;
	t_data		*data;
	size_t		x;
	size_t		y;

	data = fdf->data;
	color = 0;
	y = 0;
	while (y < data->n_row)
	{
		x = 0;
		while (x < data->n_col)
		{
			if (x + 1 < data->n_col)
				connect_coor(fdf, (t_coor){x, y, color},
					(t_coor){x + 1, y, color});
			if (y + 1 < data->n_row)
				connect_coor(fdf, (t_coor){x, y, color},
					(t_coor){x, y + 1, color});
			x++;
		}
		y++;
	}
}

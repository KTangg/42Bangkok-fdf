/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:46:22 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/07 01:25:50 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <math.h>

void	render(t_info *info, t_data *data)
{
	size_t		x;
	size_t		y;
	t_vector	unit;

	mlx_clear_window(info->mlx, info->window);
	unit = unit_vector(info);
	y = 0;
	while (y < data->n_row)
	{
		x = 0;
		while (x < data->n_col)
		{
			if (x + 1 < data->n_col)
				draw_line_x(y * (data->n_col) + x, data, info, unit);
			if (y + 1 < data->n_row)
				draw_line_y(y * (data->n_col) + x, data, info, unit);
			x++;
			data->start_x = data->start_x + (x *(unit.x.delta_x * MAGNITUDE));
			data->start_y = data->start_y + (x *(unit.x.delta_y * MAGNITUDE));
		}
		y++;
		data->start_x = INIT_X + (y *(unit.y.delta_x * MAGNITUDE));
		data->start_y = INIT_Y + (y *(unit.y.delta_y * MAGNITUDE));
	}
}

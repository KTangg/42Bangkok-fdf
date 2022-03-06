/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:46:22 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/06 22:58:58 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <math.h>

void	render(t_info *info, t_data *data)
{
	size_t	x;
	size_t	y;

	mlx_clear_window(info->mlx, info->window);
	y = 0;
	while (y < data->n_row)
	{
		x = 0;
		while (x < data->n_col)
		{
			if (x + 1 < data->n_col)
				draw_line_x(y * (data->n_col) + x, data, info);
			if (y + 1 < data->n_row)
				draw_line_y(y * (data->n_col) + x, data, info);
			x++;
		}
		y++;
	}
}

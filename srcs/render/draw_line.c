/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:59:28 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/06 23:24:36 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <math.h>

static double	deg_to_rad(int degree)
{
	double	rad;

	rad = degree * (M_PI / 180);
	return (rad);
}

void	draw_line_x(size_t index, t_data *data, t_info *info)
{
	static size_t	start_x = INIT_X;
	static size_t	start_y = INIT_Y;
	size_t	end_x;
	size_t	end_y;

	(void)data;
	(void)index;
	end_x = start_x + (cos(deg_to_rad(info->angle_x)) * MAGNITUDE);
	end_y = start_y + (cos(deg_to_rad(info->angle_y)) * MAGNITUDE);
	mlx_pixel_put(info->mlx, info->window, start_x, start_y, data->color[index]);
	start_x = end_x;
	start_y = end_y;
}

void	draw_line_y(size_t index, t_data *data, t_info *info)
{
	static size_t	start_x = INIT_X;
	static size_t	start_y = INIT_Y;
	size_t	end_x;
	size_t	end_y;

	end_x = start_x - (cos(deg_to_rad(info->angle_x)) * MAGNITUDE);
	end_y = start_y + (cos(deg_to_rad(info->angle_y)) * MAGNITUDE);
	mlx_pixel_put(info->mlx, info->window, start_x, start_y, data->color[index]);
	start_x = end_x;
	start_y = end_y;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:59:28 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/07 01:24:46 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <math.h>

void	draw_line_x(size_t index, t_data *data, t_info *info, t_vector unit)
{
	int	i;
	int	color;
	int	z_grad;
	int	color_grad;

	i = 0;
	color = data->color[index];
	z_grad = (data->attribute[index + 1] - data->attribute[index]) / MAGNITUDE;
	unit.z.delta_x = z_grad * unit.z.delta_x;
	unit.z.delta_y = z_grad * unit.z.delta_y;
	color_grad = (data->color[index + 1] - data->color[index]) / MAGNITUDE;
	while (i < MAGNITUDE)
	{
		mlx_pixel_put(info->mlx, info->window, data->start_x + (i * (unit.x.delta_x + unit.z.delta_x)), data->start_y + (i * (unit.x.delta_y + unit.z.delta_y)), color);
		color = color + color_grad;
		i++;
	}
}

void	draw_line_y(size_t index, t_data *data, t_info *info, t_vector unit)
{
	int	i;
	int	color;
	int	z_grad;
	int	color_grad;

	i = 0;
	color = data->color[index];
	z_grad = (data->attribute[index + data->n_col] - data->attribute[index]) / MAGNITUDE;
	unit.z.delta_x = z_grad * unit.z.delta_x;
	unit.z.delta_y = z_grad * unit.z.delta_y;
	color_grad = (data->color[index + data->n_col] - data->color[index]) / MAGNITUDE;
	while (i < MAGNITUDE)
	{
		mlx_pixel_put(info->mlx, info->window, data->start_x + (i * (unit.y.delta_x + unit.z.delta_x)), data->start_y + (i * (unit.y.delta_y + unit.z.delta_y)), color);
		color = color + color_grad;
		i++;
	}
}


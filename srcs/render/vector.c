/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 00:05:53 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/07 00:45:01 by spoolpra         ###   ########.fr       */
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

static t_delta	unit_x(t_info *info)
{
	double	delta_x;
	double	delta_y;
	t_delta	x;

	delta_x = cos(deg_to_rad(info->angle_x));
	delta_y = cos(deg_to_rad(info->angle_y));
	x.delta_x = delta_x;
	x.delta_y = delta_y;
	return (x);
}

static t_delta	unit_y(t_info *info)
{
	double	delta_x;
	double	delta_y;
	t_delta	y;

	delta_x = -cos(deg_to_rad(info->angle_x));
	delta_y = cos(deg_to_rad(info->angle_y));
	y.delta_x = delta_x;
	y.delta_y = delta_y;
	return (y);
}

static t_delta	unit_z(t_info *info)
{
	double	delta_x;
	double	delta_y;
	t_delta	z;

	delta_x = -cos(deg_to_rad(info->angle_x));
	delta_y = -cos(deg_to_rad(info->angle_y));
	z.delta_x = delta_x;
	z.delta_y = delta_y;
	return (z);
}

t_vector	unit_vector(t_info *info)
{
	t_vector	unit;

	unit.x = unit_x(info);
	unit.y = unit_y(info);
	unit.z = unit_z(info);
	return (unit);
}

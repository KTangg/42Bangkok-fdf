/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 00:05:53 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/08 13:44:14 by spoolpra         ###   ########.fr       */
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

static t_delta	unit_x(t_view *view)
{
	double	delta_x;
	double	delta_y;
	t_delta	x;

	delta_x = cos(deg_to_rad(view->angle)) * view->scale / 100;
	delta_y = sin(deg_to_rad(view->angle)) * view->scale / 100;
	x.delta_x = delta_x;
	x.delta_y = delta_y;
	return (x);
}

static t_delta	unit_y(t_view *view)
{
	double	delta_x;
	double	delta_y;
	t_delta	y;

	delta_x = -sin(deg_to_rad(view->angle)) * view->scale / 100;
	delta_y = cos(deg_to_rad(view->angle)) * view->scale / 100;
	y.delta_x = delta_x;
	y.delta_y = delta_y;
	return (y);
}

static t_delta	unit_z(t_delta x, t_delta y)
{
	t_delta	z;

	z.delta_x = (x.delta_x + y.delta_x) * -1;
	z.delta_y = (x.delta_y + y.delta_y) * -1;
	return (z);
}

t_vector	unit_vector(t_view *view)
{
	t_vector	unit;

	unit.x = unit_x(view);
	unit.y = unit_y(view);
	unit.z = unit_z(unit.x, unit.y);
	return (unit);
}

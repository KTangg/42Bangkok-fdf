/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 20:05:42 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/08 20:31:30 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
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

	delta_x = 1 * view->scale / 100;
	delta_y = 0 * view->scale / 100;
	y.delta_x = delta_x;
	y.delta_y = delta_y;
	return (y);
}

static t_delta	unit_z(t_view *view)
{
	double	delta_x;
	double	delta_y;
	t_delta	z;

	delta_x = 0;
	delta_y = -1 * view->scale / 100;
	z.delta_x = delta_x * view->level / MAGNITUDE;
	z.delta_y = delta_y * view->level / MAGNITUDE;
	return (z);
}

t_vector	parallel_unit_vector(t_view *view)
{
	t_vector	unit;

	unit.x = unit_x(view);
	unit.y = unit_y(view);
	unit.z = unit_z(view);
	return (unit);
}

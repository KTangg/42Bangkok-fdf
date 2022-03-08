/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 16:50:47 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/08 17:38:09 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <math.h>

static double	deg_to_rad(int degree)
{
	double	rad;

	rad = degree * (M_PI / 180);
	return (rad);
}

static t_coor	par_project(t_coor c, double z, double angle, t_coor start)
{
	t_coor	proj;

	proj.x = c.x + (cos(angle) * z);
	proj.y = c.y + (sin(angle) * z);
	proj.x = proj.x + start.x;
	proj.y = proj.y + start.y;
	return (proj);
}

static t_coor	iso_project(t_coor c, double z, double angle, t_coor start)
{
	t_coor	proj;

	proj.x = -(cos(angle) * c.x) + (cos(angle) * c.y);
	proj.y = (sin(angle) * c.x) + (sin(angle) * c.y) - (z * cos(angle * 2));
	proj.x = proj.x + start.x;
	proj.y = proj.y + start.y;
	return (proj);
}

t_coor	project(t_coor c, double z, t_view *view, t_data *data)
{
	t_coor	start;

	start = (t_coor){view->offset_x, view->offset_y, 0};
	c.x = round((c.x - (data->n_col / 2)) * view->scale / 100);
	c.y = round((c.y - (data->n_row / 2)) * view->scale / 100);
	z = z * view->scale / 100 * view->level;
	if (view->project == 0)
		return (iso_project(c, z, deg_to_rad(view->angle), start));
	else
		return (par_project(c, z, deg_to_rad(view->angle), start));
}

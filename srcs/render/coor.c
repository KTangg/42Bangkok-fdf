/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coor.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 16:25:29 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/08 00:15:27 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <math.h>

t_pen	init_pen(t_view view)
{
	t_pen	pen;

	pen.unit = unit_vector(view);
	pen.coor.x = INIT_X;
	pen.coor.y = INIT_Y;
	return (pen);
}

t_pen	move_pen(t_pen pen, int x, int y)
{
	int		move_x;
	int		move_y;
	t_delta	unit_x;
	t_delta	unit_y;

	unit_x = pen.unit.x;
	unit_y = pen.unit.y;
	move_x = (x * (int)(unit_x.delta_x * MAGNITUDE))
		+ (y * (int)(unit_y.delta_x * MAGNITUDE));
	move_y = (x * (int)(unit_x.delta_y * MAGNITUDE))
		+ (y * (int)(unit_y.delta_y * MAGNITUDE));
	pen.coor.x = pen.coor.x + move_x;
	pen.coor.y = pen.coor.y + move_y;
	return (pen);
}

t_coor	move_coor(t_pen pen, int x, int y, int z)
{
	t_coor		org;
	t_coor		new;
	t_vector	unit;

	new.c = 0;
	unit = pen.unit;
	org = pen.coor;
	new.x = org.x + (((unit.x.delta_x * x) + (unit.y.delta_x * y)
				+ (unit.z.delta_x * z)) * MAGNITUDE);
	new.y = org.y + (((unit.x.delta_y * x) + (unit.y.delta_y * y)
				+ (unit.z.delta_y * z)) * MAGNITUDE);
	return (new);
}

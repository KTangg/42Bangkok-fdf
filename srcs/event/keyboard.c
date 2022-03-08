/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:02:39 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/08 20:26:05 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	hook_keydown_3(int key, t_fdf *fdf)
{
	if (key == Q_KEY)
	{
		fdf->info->view->angle -= 10;
		if (fdf->info->view->angle < 0)
			fdf->info->view->angle = 360 + fdf->info->view->angle;
		render(fdf->info, fdf->data);
	}
	if (key == E_KEY)
	{
		fdf->info->view->angle = (fdf->info->view->angle + 10) % 360;
		render(fdf->info, fdf->data);
	}
	if (key == P_KEY)
	{
		fdf->info->view->project = 'p';
		render(fdf->info, fdf->data);
	}
	if (key == I_KEY)
	{
		fdf->info->view->project = 'i';
		render(fdf->info, fdf->data);
	}
	return (1);
}

int	hook_keydown_2(int key, t_fdf *fdf)
{
	if (key == LEFT_KEY)
	{
		fdf->info->view->offset_x += 50;
		render(fdf->info, fdf->data);
	}
	if (key == RIGHT_KEY)
	{
		fdf->info->view->offset_x -= 50;
		render(fdf->info, fdf->data);
	}
	if (key == UP_KEY)
	{
		fdf->info->view->offset_y += 50;
		render(fdf->info, fdf->data);
	}
	if (key == DOWN_KEY)
	{
		fdf->info->view->offset_y -= 50;
		render(fdf->info, fdf->data);
	}
	hook_keydown_3(key, fdf);
	return (1);
}

int	hook_keydown_1(int key, t_fdf *fdf)
{
	if (key == ESC_KEY)
		close_fdf(fdf);
	if (key == PLUS_KEY)
	{
		fdf->info->view->level += 0.05;
		render(fdf->info, fdf->data);
	}
	if (key == MINUS_KEY)
	{
		fdf->info->view->level -= 0.05;
		render(fdf->info, fdf->data);
	}
	else
		hook_keydown_2(key, fdf);
	return (1);
}

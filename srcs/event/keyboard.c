/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:02:39 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/08 16:28:33 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"

int	hook_keydown_2(int key, t_fdf *fdf)
{
	if (key == 65361)
	{
		fdf->info->view->offset_x -= 50;
		render(fdf);
	}
	if (key == 65363)
	{
		fdf->info->view->offset_x += 50;
		render(fdf);
	}
	if (key == 65362)
	{
		fdf->info->view->offset_y -= 50;
		render(fdf);
	}
	if (key == 65364)
	{
		fdf->info->view->offset_y += 50;
		render(fdf);
	}
	return (1);
}

int	hook_keydown(int key, t_fdf *fdf)
{
	printf("key: %d\n", key);
	if (key == ESC_KEY)
		close_fdf(fdf);
	if (key == PLUS_KEY)
	{
		fdf->info->view->level += 0.05;
		render(fdf);
	}
	if (key == MINUS_KEY)
	{
		fdf->info->view->level -= 0.05;
		render(fdf);
	}
	else
		hook_keydown_2(key, fdf);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:02:39 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/08 13:45:13 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"

int	hook_keydown(int key, t_fdf *fdf)
{
	if (key == ESC_KEY)
	{
		free_data(&fdf->data);
		free_info(&fdf->info);
		exit(0);
	}
	if (key == PLUS_KEY)
	{
		fdf->info.view->level += 0.05;
		render(&fdf->info, &fdf->data);
	}
	if (key == MINUS_KEY)
	{
		fdf->info.view->level -= 0.05;
		render(&fdf->info, &fdf->data);
	}
	return (1);
}

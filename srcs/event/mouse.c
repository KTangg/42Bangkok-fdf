/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:40:31 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/08 20:43:00 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

int	hook_mouse(int key, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (key == 4)
	{
		fdf->info->view->scale += 5;
		render(fdf->info, fdf->data);
	}
	if (key == 5)
	{
		if (fdf->info->view->scale > 30)
		{
			fdf->info->view->scale -= 5;
			render(fdf->info, fdf->data);
		}
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 13:40:31 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/08 16:42:29 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"

int	hook_mouse(int key, int x, int y, t_fdf *fdf)
{
	printf("%d, %d, %d\n", key, x, y);
	if (key == 4)
	{
		fdf->info->view->scale += 1;
		render(fdf);
	}
	if (key == 5)
	{
		fdf->info->view->scale -= 1;
		render(fdf);
	}
	return (1);
}

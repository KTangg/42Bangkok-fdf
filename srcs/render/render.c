/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:46:22 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/07 14:43:58 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <math.h>

void	render(t_info *info, t_data *data)
{
	int		off_x;
	int		off_y;
	t_img	*image;

	image = info->image;
	off_x = info->view->offset_x;
	off_y = info->view->offset_y;
	clear_image(info->image);
	draw_image(info->view, data, image);
	mlx_clear_window(info->mlx, info->window);
	mlx_put_image_to_window(info->mlx, info->window, image->ptr, off_x, off_y);
}

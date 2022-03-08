/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:46:22 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/08 13:29:55 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <math.h>

void	render(t_info *info, t_data *data)
{
	void	*window;
	t_img	*image;

	image = info->image;
	window = info->window;
	clear_image(info->image);
	draw_image(info->view, data, image);
	mlx_clear_window(info->mlx, info->window);
	mlx_put_image_to_window(info->mlx, window, image->mlx_img, 0, 0);
}

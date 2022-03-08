/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:46:22 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/08 16:32:03 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <math.h>

void	render(t_fdf *fdf)
{
	void	*window;
	t_img	*image;

	image = fdf->info->image;
	window = fdf->info->window;
	clear_image(image);
	draw_image(fdf);
	mlx_clear_window(fdf->info->mlx, window);
	mlx_put_image_to_window(info->mlx, window, image->mlx_img, 0, 0);
}

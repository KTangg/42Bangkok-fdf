/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:44:32 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/08 16:59:47 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"

void	clear_image(t_img *image)
{
	if (image)
	{
		if (image->ptr)
			ft_bzero(image->ptr, image->bpp * RESO_X * RESO_Y);
	}
}

void	image_put_pixel(t_img *image, int x, int y, int color)
{
	((int *)image->ptr)[(y * RESO_X) + x] = color;
}

t_img	*create_new_img(t_info *info)
{
	void	*mlx_img;
	t_img	*img;

	img = (t_img *)malloc(sizeof(t_img) * 1);
	if (!img)
		return (NULL);
	mlx_img = mlx_new_image(info->mlx, RESO_X, RESO_Y);
	if (!mlx_img)
	{
		free(img);
		return (NULL);
	}
	img->mlx_img = mlx_img;
	img->ptr = mlx_get_data_addr(mlx_img, &img->bpp, &img->line, &img->end);
	img->bpp = img->bpp / 8;
	ft_bzero(img->ptr, img->bpp * RESO_X * RESO_Y);
	return (img);
}

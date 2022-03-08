/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:44:32 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/08 18:24:04 by spoolpra         ###   ########.fr       */
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

void	draw_image(t_view *view, t_data *data, t_img *image)
{
	size_t		x;
	size_t		y;
	t_pen		pen;

	pen = init_pen(view);
	y = 0;
	while (y < data->n_row)
	{
		x = 0;
		while (x < data->n_col)
		{
			if (x + 1 < data->n_col)
				connect_x(image, pen, data, (y * data->n_col) + x);
			if (y + 1 < data->n_row)
				connect_y(image, pen, data, (y * data->n_col) + x);
			pen = move_pen(pen, 1, 0);
			x++;
		}
		pen = move_pen(pen, -x, 1);
		y++;
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 23:35:53 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/08 00:12:27 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <math.h>

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (array == NULL)
		return ;
	while (array[i] != 0)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_data(t_data *data)
{
	if (data->attribute)
		free(data->attribute);
	if (data->color)
		free(data->color);
}

void	free_image(void *mlx_ptr, t_img *image)
{
	if (!image)
		return ;
	if (image->mlx_img)
		mlx_destroy_image(mlx_ptr, image->mlx_img);
	free(image);
}

void	free_info(t_info *info)
{
	if (info->image)
		free_image(info->mlx, info->image);
	if (info->window)
		mlx_destroy_window(info->mlx, info->window);
	if (info->mlx)
		free(info->mlx);
}

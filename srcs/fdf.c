/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:51:03 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/07 14:58:47 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <math.h>

static void	usage(void)
{
	ft_printf("Usage: ./fdf [file.fdf]\n");
	exit(1);
}

static int	init_mlx(t_info *info)
{
	t_view	*view;

	info->mlx = NULL;
	info->window = NULL;
	info->mlx = mlx_init();
	if (info->mlx == NULL)
		return (0);
	info->window = mlx_new_window(info->mlx, RESO_X, RESO_Y, "FDF");
	if (info->window == NULL)
		return (0);
	info->image = create_new_img(info);
	if (!info->image)
		return (0);
	view = (t_view *)malloc(sizeof(t_view) * 1);
	if (!view)
		return (0);
	view->scale = 100;
	view->angle_x = 30;
	view->angle_y = 30;
	view->offset_x = 0;
	view->offset_y = 0;
	info->view = view;
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_data	data;

	if (argc != 2)
		usage();
	parsing_file(argv[1], &data);
	if (!init_mlx(&info))
		error_init(&data, &info);
	render(&info, &data);
	free_data(&data);
	free_info(&info);
	return (0);
}

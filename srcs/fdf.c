/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:51:03 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/08 00:27:25 by spoolpra         ###   ########.fr       */
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
	t_view	view;

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
	view.scale = 100;
	view.angle_x = 30;
	view.angle_y = 30;
	view.offset_x = 0;
	view.offset_y = 0;
	view.level = 1;
	info->view = view;
	return (1);
}

static int	hook_keydown(int key, t_fdf *fdf)
{
	printf("%d\n", key);
	if (key == ESC_KEY)
	{
		free_data(&fdf->data);
		free_info(&fdf->info);
		exit(0);
	}
	if (key == 65451)
	{
		fdf->info.view.scale += 1;
		render(&fdf->info, &fdf->data);
	}
	if (key == 65453)
	{
		fdf->info.view.scale -= 1;
		render(&fdf->info, &fdf->data);
	}
	return (1);
}

static int	hook_mouse(int key, t_fdf *fdf)
{
	if (key == 4)
	{
		fdf->info.view.scale += 1;
	}
	if (key == 5)
	{
		fdf->info.view.scale -= 1;
		render(&fdf->info, &fdf->data);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_data	data;
	t_fdf	fdf;

	if (argc != 2)
		usage();
	parsing_file(argv[1], &data);
	if (!init_mlx(&info))
		error_init(&data, &info);
	fdf.info = info;
	fdf.data = data;
	render(&info, &data);
	mlx_mouse_hook(info.window, hook_mouse, &fdf);
	mlx_key_hook(info.window, hook_keydown, &fdf);
	mlx_loop(info.mlx);
	return (0);
}

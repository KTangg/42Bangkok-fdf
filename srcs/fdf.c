/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:51:03 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/11 15:29:15 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"

static void	usage(void)
{
	ft_printf("Usage: ./fdf [file.fdf]\n");
	exit(1);
}

static t_view	*init_view(void)
{
	t_view	*view;

	view = (t_view *)malloc(sizeof(t_view) * 1);
	if (!view)
		return (NULL);
	view->level = 1;
	view->angle = 45;
	view->scale = 100;
	view->offset_x = RESO_X / 2;
	view->offset_y = RESO_Y / 2;
	view->project = 'i';
	return (view);
}

static int	init_mlx(t_info *info)
{
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
	info->view = init_view();
	return (1);
}

int	close_fdf(t_fdf *fdf)
{
	free_data(fdf->data);
	free_info(fdf->info);
	exit(0);
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
	fdf.info = &info;
	fdf.data = &data;
	render(&info, &data);
	mlx_mouse_hook(info.window, hook_mouse, &fdf);
	mlx_hook(info.window, ON_DESTROY, 0, close_fdf, &fdf);
	mlx_key_hook(info.window, hook_keydown_1, &fdf);
	mlx_loop(info.mlx);
	return (0);
}

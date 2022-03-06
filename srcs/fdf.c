/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:51:03 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/06 23:10:46 by spoolpra         ###   ########.fr       */
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
	info->mlx = NULL;
	info->window = NULL;
	info->mlx = mlx_init();
	if (info->mlx == NULL)
		return (0);
	info->window = mlx_new_window(info->mlx, RESO_X, RESO_Y, "FDF");
	if (info->window == NULL)
		return (0);
	info->angle_x = 45;
	info->angle_y = 45;
	info->zoom = 100;
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

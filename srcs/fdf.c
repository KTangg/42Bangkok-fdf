/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:51:03 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/06 13:34:16 by spoolpra         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	void	*mlx;
	t_data	data;

	if (argc != 2)
		usage();
	mlx = mlx_init();
	parsing_file(argv[1], &data);
	free_data(&data);
	free(mlx);
	return (0);
}

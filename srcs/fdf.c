/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 22:51:03 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/05 16:05:10 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <math.h>

/*static void	usage(void)
{
	ft_printf("Usage: ./fdf [file.fdf]\n");
	exit(1);
}*/

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*window;

	(void)argc;
	(void)argv;
	/*if (argc > 2)
		usage();*/
	mlx = mlx_init();
	if (mlx == NULL)
	{
		ft_printf("No mlx\n");
		return (1);
	}
	window = mlx_new_window(mlx, 30, 30, "hello world");
	if (window == NULL)
		ft_printf("No window\n");
}

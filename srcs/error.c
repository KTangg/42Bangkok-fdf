/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 22:31:43 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/06 22:52:58 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "libft.h"
#include <math.h>

void	error_init(t_data *data, t_info *info)
{
	free_data(data);
	free_info(info);
	ft_putendl_fd("Error: Invalid display.", 2);
	exit(6);
}

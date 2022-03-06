/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 23:01:57 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/06 12:21:54 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	error_open(void)
{
	ft_putendl_fd("Error: Cannot open file path.", STDERR);
	exit(1);
}

void	error_close(t_data *data)
{
	free_data(data);
	ft_putendl_fd("Error: Cannot open file path.", STDERR);
	exit(2);
}

void	error_input(char **array, t_data *data)
{
	free_data(data);
	free_array(array);
	ft_putendl_fd("Error: Input is not conform", 2);
	exit(3);
}

void	error_split(t_data *data)
{
	free_data(data);
	ft_putendl_fd("Error: Allocation for ft_split failed", 2);
	exit(4);
}

void	error_data(t_data *data)
{
	free_data(data);
	ft_putendl_fd("Error: Allocation for data failed", 2);
	exit(5);
}

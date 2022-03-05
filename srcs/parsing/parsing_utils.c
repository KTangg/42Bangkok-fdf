/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 00:03:18 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/06 00:39:15 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

size_t	array_size(char **array)
{
	size_t	size;

	size = 0;
	if (array == NULL)
		return (size);
	while (array[size] != 0)
		size++;
	return (size);
}

void	realloc_data(t_data *data, size_t new_size, size_t org_size)
{
	int	*new_color;
	int	*new_attribute;

	new_color = (int *)malloc(sizeof(int) * new_size);
	if (!new_color)
		error_data(data);
	ft_memcpy(new_color, data->color, sizeof(int) * org_size);
	if (data->color)
		free(data->color);
	data->color = new_color;
	new_attribute = (int *)malloc(sizeof(int) * new_size);
	if (!new_color)
		error_data(data);
	ft_memcpy(new_attribute, data->attribute, sizeof(int) * org_size);
	if (data->attribute)
		free(data->attribute);
	data->attribute = new_attribute;
}

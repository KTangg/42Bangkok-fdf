/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:55:20 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/06 11:49:17 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "parsing.h"

static int valid_arg(char *arg, t_data *data, int index)
{
	int		color;
	int		attribute;
	char	**array;
	size_t	array_size;

	array = ft_split(arg, ',');
	if (array == NULL)
		return (0);
	array_size = array_size(array);
	if (array_size < 1 || array_size > 2)
		return (0);
	if (!valid_attribute(array[0], &attribute))
		return (0);
	if (array_size == 1)
		color = 0;
	else
		if (!valid_rgb(array[1], &color))
			return (0);
	data->color[index] = color;
	data->attribute[index] = attribute;
	return (1);
}

static void	valid_input(char **array, t_data *data, size_t row)
{
	int				i;
	size_t			col;
	static size_t	total = 0;

	i = 0;
	col = array_size(array);
	data->n_col = col;
	total = total + col;
	if (total != (col * row))
		error_input(array, data);
	realloc_data(data, total, total - col);
	while (array[i] != 0)
	{
		if (!valid_arg(array[i++], data, total - col + i))
			error_input(array, data);
	}
}

static void	*extract_data(int fd, t_data *data)
{
	char	*line;
	char	**array;
	size_t	row;

	row = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		row++;
		array = ft_split(line, ' ');
		free(line);
		if (array == NULL)
			error_split(data);
		if (!valid_input(array, data, row))
			error_input(array, data);
		line = get_next_line(fd);
	}
	data->n_row = row;
}

void	parsing_file(char *file_path, t_data *data)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		error_open();
	data->n_col = 0;
	data->n_row = 0;
	data->color = NULL;
	data->attribute = NULL;
	extract_data(fd, data);
	if (close(fd) < 0)
		error_close(data);
}

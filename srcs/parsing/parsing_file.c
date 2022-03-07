/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:55:20 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/07 16:55:57 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

static int	valid_arg(char *arg, t_data *data, int index)
{
	char	**array;
	size_t	size;

	array = ft_split(arg, ',');
	if (array == NULL)
		return (0);
	size = array_size(array);
	if (size < 1 || size > 2)
	{
		free_array(array);
		return (0);
	}
	if (!valid_attribute(array[0], data, index))
	{
		free_array(array);
		return (0);
	}
	if (!get_rgb(array[1], data, index))
	{
		free_array(array);
		return (0);
	}
	free_array(array);
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
		if (!valid_arg(array[i], data, total - col + i))
			error_input(array, data);
		i++;
	}
	free_array(array);
}

static void	extract_data(int fd, t_data *data)
{
	char	*line;
	char	**array;
	size_t	row;

	row = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		row++;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		array = ft_split(line, ' ');
		free(line);
		if (array == NULL)
			error_split(data);
		valid_input(array, data, row);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 22:55:20 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/06 00:57:00 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "parsing.h"

static void	valid_arg(char *arg, t_data *data)
{
	int		color;
	int		attribute;
	char	**array;

	array = ft_split(arg, ',');
	if (array == NULL)
		error_split(data);

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
		if (!valid_arg(array[i++], data))
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

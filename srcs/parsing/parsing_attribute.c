/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_attribute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 11:55:31 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/06 13:05:15 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"

int	valid_attribute(char *str, t_data *data, int index)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	data->attribute[index] = ft_atoi(str);
	return (1);
}

static void	ft_strtolower(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
}

static int	char_in_str(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

static int	valid_rgb(char *rgb, t_data *data, int index)
{
	int		result;
	int		buff;
	char	*hex;

	result = 0;
	hex = "0123456789abcdef";
	ft_strtolower(rgb);
	if (*rgb == '0')
		rgb++;
	else
		return (0);
	if (*rgb == 'x')
		rgb++;
	else
		return (0);
	while (*rgb != '\0')
	{
		buff = char_in_str(*rgb++, hex);
		if (buff < 0)
			return (0);
		result = result * 16;
		result = result + buff;
	}
	data->color[index] = result;
	return (1);
}

int	get_rgb(char *str, t_data *data, int index)
{
	if (str == 0)
	{
		data->color[index] = 0;
		return (1);
	}
	else
	{
		if (!valid_rgb(str, data, index))
			return (0);
	}
	return (1);
}

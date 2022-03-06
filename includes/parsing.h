/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 23:03:14 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/06 13:04:52 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "fdf.h"

int		get_rgb(char *array, t_data *data, int index);
int		valid_attribute(char *str, t_data *data, int index);
void	error_open(void);
void	error_data(t_data *data);
void	error_close(t_data *data);
void	error_split(t_data *data);
void	error_input(char **array, t_data *data);
void	realloc_data(t_data *data, size_t new_size, size_t org_size);
size_t	array_size(char **array);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spoolpra <spoolpra@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 23:03:14 by spoolpra          #+#    #+#             */
/*   Updated: 2022/03/06 00:40:21 by spoolpra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "fdf.h"

size_t	array_size(char **array);
void	error_open(void);
void	error_data(t_data *data);
void	error_close(t_data *data);
void	error_split_line(t_data *data);
void	error_input(char **array, t_data *data);
void	realloc_data(t_data *data, size_t new_size, size_t org_size);

#endif

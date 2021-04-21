/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fc_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbeaufay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 14:19:25 by vbeaufay          #+#    #+#             */
/*   Updated: 2021/04/21 14:19:52 by vbeaufay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct.h"
#include "error.h"

static int	get_value(char **line)
{
	int	temp;
	int	size;

	size = 0;
	if (**line == '+' || **line == '-')
		return (-1);
	temp = ft_atoi(*line);
	if (temp < 0 || temp > 255)
		return (-1);
	while (ft_isdigit(*(*line + size)))
		size++;
	*line += size;
	return (temp);
}

static int	next_value(char **line)
{
	int	size;

	size = 0;
	while (*(*line + size) == ' ')
		size++;
	if (*(*line + size) != ',')
		return (0);
	size++;
	while (*(*line + size) == ' ')
		size++;
	*line += size;
	return (1);
}

void		parse_floor(t_temp *temp)
{
	char	*line;

	line = temp->trim + 1;
	if (!(*line == ' '))
		free_tmp_err("invalid floor line", temp, 3);
	while (*line == ' ')
		line++;
	if ((temp->f[0] = get_value(&line)) < 0)
		free_tmp_err("invalid floor line", temp, 3);
	if (!(next_value(&line)))
		free_tmp_err("missing \',\' in floor line", temp, 3);
	if ((temp->f[1] = get_value(&line)) < 0)
		free_tmp_err("invalid floor line", temp, 3);
	if (!(next_value(&line)))
		free_tmp_err("missing \',\' in floor line", temp, 3);
	if ((temp->f[2] = get_value(&line)) < 0)
		free_tmp_err("invalid floor line", temp, 3);
	while (*line)
	{
		if (*line != ' ')
			free_tmp_err("invalid floor line", temp, 3);
		line++;
	}
}

void		parse_ceiling(t_temp *temp)
{
	char	*line;

	line = temp->trim + 1;
	if (!(*line == ' '))
		free_tmp_err("invalid ceiling line", temp, 3);
	while (*line == ' ')
		line++;
	if ((temp->c[0] = get_value(&line)) < 0)
		free_tmp_err("invalid ceiling line", temp, 3);
	if (!(next_value(&line)))
		free_tmp_err("missing \',\' in ceiling line", temp, 3);
	if ((temp->c[1] = get_value(&line)) < 0)
		free_tmp_err("invalid ceiling line", temp, 3);
	if (!(next_value(&line)))
		free_tmp_err("missing \',\' in ceiling line", temp, 3);
	if ((temp->c[2] = get_value(&line)) < 0)
		free_tmp_err("invalid ceiling line", temp, 3);
	while (*line)
	{
		if (*line != ' ')
			free_tmp_err("invalid ceiling line", temp, 3);
		line++;
	}
}

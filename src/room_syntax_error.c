/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_syntax_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 17:51:33 by jde-maga          #+#    #+#             */
/*   Updated: 2016/06/30 18:16:18 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		room_check_y(int i, char *line)
{
	char *buf;

	while (line[i])
		i++;
	buf = ft_strnew(i);
	if (!ft_isint(ft_strncpy(buf, line, i)))
		lemin_error("Coord_Y is not a valid int");
	free(buf);
}

void			room_syntax_error(char *line)
{
	int		i;
	char	*buf;

	i = 0;
	while (*line && *line != ' ')
		line++;
	if (*line == 0)
		lemin_error("No coordinates on a room definition");
	if (!ft_isdigit(*(++line)) && *line != '-')
		lemin_error("Invalid syntax on a room definition");
	while (line[i] != ' ' && line[i])
		i++;
	buf = ft_strnew(i);
	if (!ft_isint(ft_strncpy(buf, line, i)))
		lemin_error("Coord_X is not a valid int");
	free(buf);
	line += i;
	if (*line == 0)
		lemin_error("No Y coordinates on a room definition");
	if (!ft_isdigit(*(++line)) && *line != '-')
		lemin_error("Invalid syntax on a room definition");
	room_check_y(i, line);
}

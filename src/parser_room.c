/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 14:09:44 by jde-maga          #+#    #+#             */
/*   Updated: 2016/07/21 18:57:41 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		room_first_letter(t_room **room)
{
	int i;

	i = 0;
	while (room[i] != NULL)
	{
		if (ft_strchr(room[i]->name, '-') || room[i]->name[0] == 'L'
			|| room[i]->name[0] == '#')
			lemin_error("A room name is invalid");
		i++;
	}
}

void			room_error(t_room **room, t_linkid *linkid)
{
	int		i;
	int		j;

	room_first_letter(room);
	i = 0;
	while (room[i] != NULL)
	{
		j = i + 1;
		while (room[j] != NULL)
		{
			if (room[i]->coord_x == room[j]->coord_x &&
				room[i]->coord_y == room[j]->coord_y)
				lemin_error("2 rooms have the same coordinates");
			if (!ft_strcmp(room[i]->name, room[j]->name))
				lemin_error("2 rooms have the same name");
			j++;
		}
		i++;
	}
	if (linkid->start_id < 0 || linkid->end_id < 0)
		lemin_error("start / end not properly defined");
}

static void		room_init_handle(char **line, t_room **room, int id)
{
	int		i;
	char	*buf;

	i = 0;
	room_syntax_error(*line);
	while ((*line)[i] != ' ')
		i++;
	*room = lemin_room_init();
	(*room)->id = id;
	(*room)->name = ft_strnew(i + 1);
	(*room)->name = ft_strncpy((*room)->name, *line, i);
	*line += i + 1;
	i = 0;
	while ((*line)[i] != ' ')
		i++;
	buf = ft_strnew(i);
	ft_strncpy(buf, *line, i);
	(*room)->coord_x = ft_atoi(buf);
	*line += i + 1;
	i = 0;
	free(buf);
}

t_room			*room_parser(char *line, t_linkid *linkid)
{
	t_room		*room;
	static int	id;
	int			i;
	char		*buf;

	id++;
	if (linkid->start_id == -2)
		linkid->start_id = id;
	if (linkid->end_id == -2)
		linkid->end_id = id;
	room_init_handle(&line, &room, id);
	i = 0;
	while (line[i])
		i++;
	buf = ft_strnew(i);
	ft_strncpy(buf, line, i);
	room->coord_y = ft_atoi(buf);
	free(buf);
	return (room);
}

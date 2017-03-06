/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 14:42:07 by jde-maga          #+#    #+#             */
/*   Updated: 2016/07/21 19:23:19 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static void		command_detector(char **line, t_linkid *linkid, int *sig)
{
	if (!ft_strcmp(*line, "##start"))
	{
		if (linkid->start_id == -2 || linkid->end_id == -2)
			lemin_error("Commands start/end are messed up !");
		if (linkid->start_id != -1)
			lemin_error("Already have a start !");
		linkid->start_id = -2;
		*sig = skip_comments(line);
	}
	else if (!ft_strcmp(*line, "##end"))
	{
		if (linkid->start_id == -2 || linkid->end_id == -2)
			lemin_error("Commands start/end are messed up !");
		if (linkid->end_id != -1)
			lemin_error("Already have an end !");
		linkid->end_id = -2;
		*sig = skip_comments(line);
	}
	else
	{
		ft_printf("invalid command : [%s], ignoring.\n", *line);
		*sig = skip_comments(line);
	}
}

static int		tube_parsing(char **line, t_room **room)
{
	if (tube_parser(*line, room) == -1)
	{
		ft_printf("WARNING : Tube syntax invalid. Stopping parsing...\n");
		return (-1);
	}
	return (skip_comments(line));
}

static void		ant_number_parser(char *line, int *ants)
{
	if (!ft_isint(line))
		lemin_error("Number of ants is not an int value !");
	*ants = ft_atoi(line);
	if (ants <= 0)
		lemin_error("Number of ants is inferior or equal to 0 !");
}

static int		line_is_command(char *line)
{
	if (ft_strlen(line) > 1 && line[0] == '#' && line[1] == '#')
		return (1);
	return (0);
}

int				file_parser(char **line, t_room **room, t_linkid *linkid,
							int *ants)
{
	int sig;
	int i;

	i = 0;
	skip_comments(line);
	ant_number_parser(*line, ants);
	sig = skip_comments(line);
	while (!line_is_tube(*line) && sig != -1)
	{
		if (!ft_strcmp(*line, "##start") || !ft_strcmp(*line, "##end")
			|| line_is_command(*line))
		{
			command_detector(line, linkid, &sig);
			continue ;
		}
		room[i] = room_parser(*line, linkid);
		sig = skip_comments(line);
		i++;
	}
	room[i] = NULL;
	room_error(room, linkid);
	while (sig != -1)
		sig = tube_parsing(line, room);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 13:56:02 by jde-maga          #+#    #+#             */
/*   Updated: 2016/07/21 19:52:48 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int				lemin_error(char *s)
{
	ft_printf("ERROR : %s\n", s);
	exit(0);
}

int				skip_comments(char **line)
{
	char *s;

	if (!get_next_line(0, line))
		return (-1);
	s = *line;
	while (s[0] == '#' && s[1] != '#')
	{
		if (!get_next_line(0, line))
			return (-1);
		s = *line;
	}
	return (0);
}

static int		start_end_linked(t_room **room, t_linkid *linkid)
{
	int i;

	i = 0;
	while (room[START_ROOM]->link[i])
	{
		if (room[START_ROOM]->link[i]->id == room[END_ROOM]->id)
			return (1);
		i++;
	}
	return (0);
}

static int		**solver_start_end_linked(void)
{
	int **otp;

	otp = malloc(sizeof(int *) * 2);
	otp[0] = malloc(sizeof(int) * 2);
	otp[0][0] = 1;
	otp[0][1] = -1;
	otp[1] = NULL;
	return (otp);
}

int				main(void)
{
	char		**line;
	t_room		**room;
	t_linkid	*linkid;
	int			ants;
	int			**allpath;

	room = malloc(sizeof(t_room) * 10000);
	line = malloc(sizeof(char *));
	linkid = lemin_linkid_init();
	file_parser(line, room, linkid, &ants);
	if (ants < 1)
		lemin_error("Ants is negative or null value.");
	if (!path_verify(room, linkid))
		return (0);
	if (start_end_linked(room, linkid))
		allpath = solver_start_end_linked();
	else
		allpath = solver(room, linkid);
	display_data(room, linkid, ants);
	ant_pusher(ants, allpath, linkid, room);
	free(room);
	free(line);
	free(linkid);
	ptr_list(NULL, DESTROYLIST);
	return (0);
}

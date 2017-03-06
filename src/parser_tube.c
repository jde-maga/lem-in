/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_tube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 14:23:36 by jde-maga          #+#    #+#             */
/*   Updated: 2016/07/21 19:02:27 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int	no_matching_room(t_room **room, char *room1, char *room2)
{
	int i;
	int room1_match;
	int room2_match;

	room1_match = 0;
	room2_match = 0;
	i = 0;
	while (room[i])
	{
		if (!ft_strcmp(room1, room[i]->name))
			room1_match = 1;
		if (!ft_strcmp(room2, room[i]->name))
			room2_match = 1;
		i++;
	}
	if (!room1_match || !room2_match)
		return (1);
	return (0);
}

static int	tube_parser_syntax_error(char *line, t_room **room, char **r1,
										char **r2)
{
	int		i;
	char	*buf;
	char	*buf2;

	i = 0;
	while (line[i] != '-' && line[i])
		i++;
	if (!line[i])
		return (1);
	buf = ft_strnew(i);
	ft_strncpy(buf, line, i);
	line += i + 1;
	if (!line[0])
		return (1);
	i = 0;
	while (line[i])
		i++;
	buf2 = ft_strnew(i);
	ft_strncpy(buf2, line, i);
	if (!ft_strcmp(buf, buf2) || no_matching_room(room, buf, buf2))
		return (1);
	*r1 = buf;
	*r2 = buf2;
	return (0);
}

int			line_is_tube(char *line)
{
	int i;

	i = 0;
	while (line[i] != ' ' && line[i])
	{
		if (line[i] == '-')
			return (1);
		i++;
	}
	return (0);
}

static void	lemin_linker(t_room *r1, t_room *r2)
{
	int i;

	i = 0;
	if (r1->link == NULL)
	{
		r1->link = malloc(sizeof(t_room *) * 2);
		r1->link[0] = r2;
		r1->link[1] = NULL;
	}
	else
	{
		while (r1->link[i] != NULL)
			i++;
		r1->link = ft_realloc(r1->link, sizeof(t_room *) * (i + 2));
		r1->link[i] = r2;
		r1->link[i + 1] = NULL;
	}
}

int			tube_parser(char *line, t_room **room)
{
	char	*r1;
	char	*r2;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (tube_parser_syntax_error(line, room, &r1, &r2))
		return (-1);
	while (ft_strcmp(room[i]->name, r1))
		i++;
	while (ft_strcmp(room[j]->name, r2))
		j++;
	if (duplicate_tube(*room[i], *room[j]))
		return (-1);
	lemin_linker(room[i], room[j]);
	lemin_linker(room[j], room[i]);
	return (0);
}

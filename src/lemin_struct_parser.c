/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin_struct_parser.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 16:08:59 by jde-maga          #+#    #+#             */
/*   Updated: 2016/07/21 19:57:45 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

t_room			*lemin_room_init(void)
{
	t_room *room;

	room = malloc(sizeof(int) * 4 + sizeof(char *) + sizeof(t_room **));
	room->id = 0;
	room->coord_x = 0;
	room->coord_y = 0;
	room->reached = INT_MAX;
	room->name = NULL;
	room->link = NULL;
	return (room);
}

t_linkid		*lemin_linkid_init(void)
{
	t_linkid *linkid;

	linkid = malloc(sizeof(int) * 2);
	linkid->start_id = -1;
	linkid->end_id = -1;
	return (linkid);
}

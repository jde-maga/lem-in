/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 18:20:20 by jde-maga          #+#    #+#             */
/*   Updated: 2016/06/10 18:33:56 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		mark_room(t_room *current_room, int *path, int backtrack)
{
	if (!backtrack)
	{
		add_path(path, current_room->id);
		current_room->reached = calculate_reach(path, current_room->id);
	}
	return (0);
}

int		go_back(t_room **rooms, t_room **current_room, int *path, int *length)
{
	remove_path(path);
	*length = *length - 1;
	*current_room = lemin_backtrack(path, rooms);
	return (1);
}

int		go_forward(t_room **current_room, int *length, int *i)
{
	*length = *length + 1;
	*current_room = (*current_room)->link[*i];
	return (1);
}

t_room	*lemin_backtrack(int *path, t_room **all_rooms)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (path[i] != -1)
		i++;
	while (all_rooms[j]->id != path[i - 1])
		j++;
	return (all_rooms[j]);
}

int		search_end(t_room *room, t_linkid *linkid)
{
	int i;

	if (room->link == NULL)
		return (0);
	i = 0;
	while (room->link[i])
	{
		if (room->link[i]->id == linkid->end_id)
			return (1);
		i++;
	}
	return (0);
}

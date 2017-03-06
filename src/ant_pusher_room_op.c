/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_pusher_room_op.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 18:32:50 by jde-maga          #+#    #+#             */
/*   Updated: 2016/07/21 18:37:48 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		ant_room_check(t_ants **ant, int antnbr)
{
	int i;

	i = 0;
	while (i != antnbr)
	{
		if (ant[i]->room != -1)
			return (0);
		i++;
	}
	return (1);
}

void	push_occupied_room(t_ants *ant, int *occupied_rooms)
{
	int i;

	i = 0;
	while (occupied_rooms[i] != -1 && occupied_rooms[i] != 0)
		i++;
	occupied_rooms[i] = ant->room;
}

void	clear_occupied_room(t_ants *ant, int *occupied_rooms)
{
	int i;

	i = 0;
	while (ant->room != occupied_rooms[i])
		i++;
	occupied_rooms[i] = 0;
}

int		ant_next_room(t_ants *ant)
{
	int i;

	i = 0;
	while (ant->room != ant->path[i])
		i++;
	return (ant->path[i + 1]);
}

int		next_room_is_occupied(t_ants *ant, int *occupied_rooms)
{
	int i;

	i = 0;
	while (occupied_rooms[i] != -1)
	{
		if (occupied_rooms[i] == ant_next_room(ant))
			return (1);
		i++;
	}
	return (0);
}

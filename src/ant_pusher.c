/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_pusher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/09 16:47:59 by jde-maga          #+#    #+#             */
/*   Updated: 2016/07/21 19:24:33 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static t_ants	*ant_init(int ant, t_room *start_room, int *path)
{
	t_ants *otp;

	otp = malloc(sizeof(int) * 2 + sizeof(int *));
	otp->ant = ant;
	otp->room = start_room->id;
	otp->path = path;
	return (otp);
}

static int		jump_room(t_ants *ant, int *occupied_rooms, t_linkid *linkid)
{
	if (ant->room == -1)
		return (0);
	else if (next_room_is_occupied(ant, occupied_rooms))
		return (0);
	else if (ant_next_room(ant) == -1)
	{
		if (ant->room != linkid->start_id)
			clear_occupied_room(ant, occupied_rooms);
		ant->room = -1;
	}
	else
	{
		if (ant->room != linkid->start_id)
			clear_occupied_room(ant, occupied_rooms);
		ant->room = ant_next_room(ant);
		push_occupied_room(ant, occupied_rooms);
	}
	return (1);
}

static t_ants	**init_ant_array(int **paths, int ants, t_room **room,
									t_linkid *linkid)
{
	int		i;
	int		j;
	t_ants	**ant_array;

	i = 0;
	j = 0;
	ant_array = malloc(sizeof(t_ants *) * (ants + 1));
	while (i != ants)
	{
		ant_array[i] = ant_init(i, room[START_ROOM], paths[j]);
		i++;
		j++;
		if (paths[j] == NULL)
			j = 0;
	}
	ant_array[i] = NULL;
	return (ant_array);
}

static void		reset_var_and_endl(int *i, int *sig)
{
	*i = 0;
	*sig = 0;
	ft_printf("\n");
}

int				ant_pusher(int ants, int **paths, t_linkid *linkid,
							t_room **room)
{
	int		i;
	int		sig;
	t_ants	**ant;
	int		*occupied_rooms;

	occupied_rooms = int_array_init(-1, number_of_rooms(room));
	clean_path(paths, ants);
	sig = 0;
	ant = init_ant_array(paths, ants, room, linkid);
	i = 0;
	while (!ant_room_check(ant, ants))
	{
		while (i != ants)
		{
			if (jump_room(ant[i], occupied_rooms, linkid))
			{
				print_ant_move(ant[i], room, linkid, sig);
				sig = 1;
			}
			i++;
		}
		reset_var_and_endl(&i, &sig);
	}
	return (0);
}

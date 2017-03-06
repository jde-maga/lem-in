/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 16:10:03 by jde-maga          #+#    #+#             */
/*   Updated: 2016/07/21 19:04:34 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static int		tube_displayed(int target_id, int *room_displayed)
{
	int i;

	i = 0;
	while (room_displayed[i])
	{
		if (room_displayed[i] == target_id)
			return (1);
		i++;
	}
	return (0);
}

static void		add_room_displayed(int *room_array, int id)
{
	int i;

	i = 0;
	while (room_array[i])
		i++;
	room_array[i] = id;
}

static void		display_rooms(t_room **room, t_linkid *linkid)
{
	int i;

	i = 0;
	while (room[i])
	{
		if (room[i]->id == linkid->start_id)
			ft_printf("##start\n");
		else if (room[i]->id == linkid->end_id)
			ft_printf("##end\n");
		ft_printf("%s %d %d\n", room[i]->name, room[i]->coord_x,
				room[i]->coord_y);
		i++;
	}
}

void			display_data(t_room **room, t_linkid *linkid, int ants)
{
	int i;
	int j;
	int *room_displayed;

	room_displayed = int_array_init(0, 10000);
	i = 0;
	j = 0;
	ft_printf("%d\n", ants);
	display_rooms(room, linkid);
	while (room[i])
	{
		while (room[i]->link && room[i]->link[j])
		{
			if (!tube_displayed(room[i]->link[j]->id, room_displayed))
				ft_printf("%s-%s\n", room[i]->name, room[i]->link[j]->name);
			j++;
		}
		j = 0;
		add_room_displayed(room_displayed, room[i]->id);
		i++;
	}
	ft_printf("\n");
	free(room_displayed);
}

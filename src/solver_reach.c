/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_reach.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 18:28:16 by jde-maga          #+#    #+#             */
/*   Updated: 2016/06/10 18:29:20 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		calculate_reach(int *path, int room_id)
{
	int i;

	i = 0;
	while (path[i] != room_id)
		i++;
	return (i + 1);
}

void	reset_room_reach(t_room **room)
{
	int i;

	i = 0;
	while (room[i])
	{
		room[i]->reached = INT_MAX;
		i++;
	}
}

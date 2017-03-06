/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_steps.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 18:34:40 by jde-maga          #+#    #+#             */
/*   Updated: 2016/06/10 18:38:01 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	add_steps(int *path, int *steps, t_linkid *linkid)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (steps[j] != -1)
		j++;
	while (path[i] != -1)
	{
		if (path[i] == linkid->start_id)
		{
			i++;
			continue;
		}
		steps[j] = path[i];
		i++;
		j++;
	}
}

int		already_stepped(int room_id, int *steps, t_linkid *linkid)
{
	int i;

	i = 0;
	while (steps[i] != -1)
	{
		if (steps[i] == room_id && room_id != linkid->start_id)
			return (1);
		i++;
	}
	return (0);
}

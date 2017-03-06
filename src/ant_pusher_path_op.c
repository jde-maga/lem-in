/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_pusher_path_op.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 18:38:20 by jde-maga          #+#    #+#             */
/*   Updated: 2016/06/30 18:43:09 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		calculate_size(int *path)
{
	int i;

	i = 0;
	while (path[i] != -1)
		i++;
	return (i);
}

void	clean_path(int **paths, int ants)
{
	int i;

	i = 0;
	while (paths[i] != NULL)
		i++;
	i--;
	while (calculate_size(paths[i]) - ants > 0 && i != 0)
	{
		paths[i] = NULL;
		i--;
	}
}

void	print_ant_move(t_ants *ant, t_room **room, t_linkid *linkid,
						int sig)
{
	if (sig)
		ft_printf(" ");
	if (ant->room == -1)
		ft_printf("L%d-%s", ant->ant + 1, room[END_ROOM]->name);
	else
		ft_printf("L%d-%s", ant->ant + 1, room[ant->room - 1]->name);
}

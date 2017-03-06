/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_tube.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/30 17:44:49 by jde-maga          #+#    #+#             */
/*   Updated: 2016/06/30 17:48:29 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		duplicate_tube(t_room r1, t_room r2)
{
	int i;

	if (r1.link == NULL || r2.link == NULL)
		return (0);
	i = 0;
	while (r2.link[i])
	{
		if (r1.id == r2.link[i]->id)
		{
			ft_printf("Warning ! Duplicate tube between %s and %s.\n",
						r1.name, r2.name);
			return (1);
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_verify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 18:43:53 by jde-maga          #+#    #+#             */
/*   Updated: 2016/06/10 16:03:41 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		path_verify(t_room **room, t_linkid *linkid)
{
	if (room[START_ROOM]->link == NULL)
		lemin_error("Start room has no tubes");
	if (room[END_ROOM]->link == NULL)
		lemin_error("End room has no tubes");
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 18:23:18 by jde-maga          #+#    #+#             */
/*   Updated: 2016/07/21 19:42:45 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	add_path(int *path, int room_id)
{
	int i;

	i = 0;
	while (path[i] != -1)
		i++;
	path[i] = room_id;
}

void	remove_path(int *path)
{
	int i;

	i = 0;
	while (path[i] != -1)
		i++;
	path[i - 1] = -1;
}

int		*copy_path(int *path)
{
	int *otp;
	int i;

	i = 0;
	while (path[i] != -1)
		i++;
	otp = malloc(sizeof(int) * (i + 1));
	i = 0;
	while (path[i] != -1)
	{
		otp[i] = path[i];
		i++;
	}
	otp[i] = -1;
	ptr_list(otp, ADDLIST);
	return (otp);
}

void	clear_path(int *path)
{
	int i;

	i = 0;
	while (path[i] != -1)
	{
		path[i] = -1;
		i++;
	}
}

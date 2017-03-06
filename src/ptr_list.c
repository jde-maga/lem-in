/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 19:36:16 by jde-maga          #+#    #+#             */
/*   Updated: 2016/07/21 19:56:01 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

void	ptr_list(void *ptr, int mode)
{
	static void **ptr_list;
	static int	i;

	if (ptr_list == NULL)
		ptr_list = malloc(sizeof(void *) * 8192);
	if (mode == ADDLIST)
	{
		ptr_list[i] = ptr;
		i++;
		ptr_list[i] = NULL;
	}
	if (mode == DESTROYLIST)
	{
		i = 0;
		while (ptr_list[i] != NULL)
		{
			free(ptr_list[i]);
			i++;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_array_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 17:36:18 by jde-maga          #+#    #+#             */
/*   Updated: 2016/06/10 17:38:29 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int		*int_array_init(int value, int size)
{
	int	*array;
	int i;

	array = malloc(sizeof(int) * size);
	i = 0;
	while (i != size)
	{
		array[i] = value;
		i++;
	}
	return (array);
}

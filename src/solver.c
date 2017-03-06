/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 15:40:33 by jde-maga          #+#    #+#             */
/*   Updated: 2016/07/21 19:51:21 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

static t_solver	solver_struct_init(t_room **room, t_linkid *linkid)
{
	t_solver s;

	s.i = 0;
	s.k = 0;
	s.length = 0;
	s.minlength = INT_MAX;
	s.minpath = NULL;
	s.backtrack = 0;
	s.all_paths = malloc(sizeof(int *) * 1024);
	s.steps = int_array_init(-1, number_of_rooms(room));
	s.path = int_array_init(-1, number_of_rooms(room));
	s.current_room = room[START_ROOM];
	ptr_list(s.all_paths, ADDLIST);
	return (s);
}

static void		reset_algo(t_solver *s, t_room **room, t_linkid *linkid)
{
	reset_room_reach(room);
	add_steps(s->minpath, s->steps, linkid);
	s->all_paths[s->k] = copy_path(s->minpath);
	s->k++;
	clear_path(s->path);
	s->minlength = INT_MAX;
	s->minpath = NULL;
}

static int		core_algo(t_solver *s, t_room **room, t_linkid *linkid)
{
	while (s->current_room->link[s->i] != NULL &&
			(s->current_room->link[s->i]->reached <=
			calculate_reach(s->path, s->current_room->id) + 1 ||
			already_stepped(s->current_room->link[s->i]->id, s->steps, linkid)))
		s->i++;
	if (s->current_room->link[s->i] == NULL)
	{
		if (s->current_room->id == linkid->start_id)
		{
			if (s->minpath == NULL)
			{
				free(s->steps);
				free(s->path);
				return (1);
			}
			reset_algo(s, room, linkid);
		}
		else
			s->backtrack = go_back(room, &s->current_room, s->path,
									&s->length);
	}
	else
		go_forward(&s->current_room, &s->length, &s->i);
	s->i = 0;
	return (0);
}

int				**solver(t_room **room, t_linkid *linkid)
{
	t_solver s;

	s = solver_struct_init(room, linkid);
	while (1)
	{
		s.backtrack = mark_room(s.current_room, s.path, s.backtrack);
		if (search_end(s.current_room, linkid))
		{
			if (s.length + 1 < s.minlength)
			{
				s.minpath = copy_path(s.path);
				s.minlength = s.length + 1;
			}
			s.backtrack = go_back(room, &s.current_room, s.path, &s.length);
		}
		else
		{
			if (core_algo(&s, room, linkid))
				return (s.all_paths);
		}
	}
}

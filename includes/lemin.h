/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 14:09:27 by jde-maga          #+#    #+#             */
/*   Updated: 2016/07/21 19:41:35 by jde-maga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# include <libft.h>

# define START_ROOM linkid->start_id - 1
# define END_ROOM linkid->end_id - 1
# define ADDLIST 1
# define DESTROYLIST 0

typedef struct s_room	t_room;
struct					s_room
{
	int		id;
	int		coord_x;
	int		coord_y;
	int		reached;
	char	*name;
	t_room	**link;
};

typedef struct s_linkid	t_linkid;
struct					s_linkid
{
	int start_id;
	int end_id;
};

typedef struct s_ants	t_ants;
struct					s_ants
{
	int ant;
	int room;
	int *path;
};

typedef struct			s_solver
{
	int		**all_paths;
	t_room	*current_room;
	int		*steps;
	int		*path;
	int		*minpath;
	int		i;
	int		length;
	int		minlength;
	int		backtrack;
	int		k;
}						t_solver;

int						file_parser(char **line, t_room **room,
									t_linkid *linkid, int *ants);
int						lemin_error(char *s);
int						skip_comments(char **line);
t_room					*lemin_room_init(void);
void					room_error(t_room **room, t_linkid *linkid);
t_room					*room_parser(char *line, t_linkid *linkid);
int						tube_parser(char *line, t_room **room);
int						line_is_tube(char *line);
int						path_verify(t_room **room, t_linkid *linkid);
t_linkid				*lemin_linkid_init(void);
int						**solver(t_room **room, t_linkid *linkid);
int						ant_pusher(int ants, int **paths,
									t_linkid *linkid, t_room **room);
void					display_data(t_room **room, t_linkid *linkid, int ants);
int						number_of_rooms(t_room **room);
int						*int_array_init(int value, int size);

int						mark_room(t_room *current_room,
									int *path, int backtrack);
int						go_back(t_room **rooms, t_room **current_room,
								int *path, int *length);
int						go_forward(t_room **current_room, int *length, int *i);
t_room					*lemin_backtrack(int *path, t_room **all_rooms);
int						search_end(t_room *room, t_linkid *linkid);

void					clear_path(int *path);
int						*copy_path(int *path);
void					remove_path(int *path);
void					add_path(int *path, int room_id);

int						calculate_reach(int *path, int room_id);
void					reset_room_reach(t_room **room);

void					add_steps(int *path, int *steps, t_linkid *linkid);
int						already_stepped(int room_id,
										int *steps, t_linkid *linkid);

int						duplicate_tube(t_room r1, t_room r2);

void					room_syntax_error(char *line);

int						ant_room_check(t_ants **ant, int antnbr);
void					push_occupied_room(t_ants *ant, int *occupied_rooms);
void					clear_occupied_room(t_ants *ant, int *occupied_rooms);
int						ant_next_room(t_ants *ant);
int						next_room_is_occupied(t_ants *ant, int *occupied_rooms);

int						calculate_size(int *path);
void					clean_path(int **paths, int ants);
void					print_ant_move(t_ants *ant, t_room **room,
										t_linkid *linkid, int sig);

void					ptr_list(void *ptr, int mode);

#endif

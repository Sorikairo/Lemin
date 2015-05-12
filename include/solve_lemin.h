/*
** solve_lemin.h for lemin in /home/fourri_l/Projects/lemin
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Apr 30 15:49:10 2014 Laurent Fourrier
** Last update Sun May  4 12:08:19 2014 Laurent Fourrier
*/

#ifndef SOLVE_LEMIN_H_
# define SOLVE_LEMIN_H_

# include <tlist.h>
# include "list_lemin.h"

void	solve_lemin(t_lemin *lemin);

/*
** Basic solving algorithm (hugely influenced by A*)
*/
t_list	*get_path_list(t_lemin *lemin);
t_list	*compute_paths(t_lemin *lemin, t_list *paths, t_list *old, t_list *rtn);

/*
** Print the solution
*/
void	print_solution(t_list *sol, int ants);

/*
** Utility functions used by the solving algorithm
*/
t_list	*add_old_nodes(t_list *old, t_list *paths);
t_list	*update_paths(t_lemin *lemin, t_list *paths, t_list *old);
char	tl_room_exists(t_list *list, char *name);
char	*tl_get_last_node(t_list *list);
t_list	*tl_get_shortest_path(t_list *path_list);

#endif

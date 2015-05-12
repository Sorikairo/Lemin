/*
** compute_paths.c for lemin in /home/fourri_l/Projects/repo-lemin
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri May  2 16:24:53 2014 Laurent Fourrier
** Last update Sun May  4 13:47:43 2014 Laurent Fourrier
*/

#include <tlist.h>
#include "list_lemin.h"
#include "solve_lemin.h"

static t_list	*add_solutions(t_list *paths, t_list *rtn, char *end)
{
  char		*last_node;

  while (paths)
    {
      last_node = tl_get_last_node(paths->data);
      if (strcmp(end, last_node) == 0)
	rtn = tl_add(rtn, paths->data);
      paths = paths->next;
    }
  return (rtn);
}

static t_list	*remove_solutions(t_list *paths, t_list *rtn)
{
  while (rtn)
    {
      paths = tl_remove_dta(paths, rtn->data);
      rtn = rtn->next;
    }
  return (paths);
}

t_list		*compute_paths(t_lemin *lemin, t_list *paths,
			       t_list *old, t_list *rtn)
{
  t_list	*next_paths;

  if (!paths)
    return (rtn);
  old = add_old_nodes(old, paths);
  next_paths = update_paths(lemin, paths, old);
  rtn = add_solutions(next_paths, rtn, lemin->end);
  next_paths = remove_solutions(next_paths, rtn);
  return (compute_paths(lemin, next_paths, old, rtn));
}

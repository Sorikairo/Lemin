/*
** add_old_nodes.c for lemin in /home/fourri_l/Projects/repo-lemin
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May  3 17:39:32 2014 Laurent Fourrier
** Last update Sat May  3 17:43:39 2014 Laurent Fourrier
*/

#include <tlist.h>
#include "solve_lemin.h"

t_list		*add_old_nodes(t_list *old, t_list *paths)
{
  void		tl_addnode_it(void *data)
  {
    char	*last_node;
    t_list	*path;

    path = data;
    last_node = tl_get_last_node(path);
    if (!tl_room_exists(old, last_node))
      old = tl_add(old, last_node);
  }
  tl_iterate(paths, &tl_addnode_it);
  return (old);
}

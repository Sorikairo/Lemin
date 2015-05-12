/*
** update_paths.c for lemin in /home/fourri_l/Projects/repo-lemin
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May  3 17:44:03 2014 Laurent Fourrier
** Last update Sun May  4 13:34:16 2014 Laurent Fourrier
*/

#include <stddef.h>
#include <string.h>
#include <tlist.h>
#include "list_lemin.h"
#include "solve_lemin.h"

static t_list	*append_path(t_list *path, char *room)
{
  t_list	*rtn;

  rtn = NULL;
  while (path)
    {
      rtn = tl_add(rtn, path->data);
      path = path->next;
    }
  return (tl_add(rtn, strdup(room)));
}

static t_list	*update_path(t_room *room, t_list *rtn,
			     t_list *path, t_list *old)
{
  int		it;

  it = 0;
  while (room->link[it])
    {
      if (!tl_room_exists(old, room->link[it]))
	rtn = tl_add(rtn, append_path(path, room->link[it]));
      it++;
    }
  return (rtn);
}

t_list		*update_paths(t_lemin *lemin, t_list *paths, t_list *old)
{
  t_list	*rtn;

  void		tl_update_it(void *data)
  {
    char	*last_node;
    t_room	*room;
    t_list	*path;

    path = data;
    last_node = tl_get_last_node(path);
    room = get_room(lemin, last_node);
    if (room)
      rtn = update_path(room, rtn, path, old);
  }
  rtn = NULL;
  tl_iterate(paths, &tl_update_it);
  return (rtn);
}

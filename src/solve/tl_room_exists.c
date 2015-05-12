/*
** tl_room_exists.c for lemin in /home/fourri_l/Projects/repo-lemin
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri May  2 16:39:49 2014 Laurent Fourrier
** Last update Sat May  3 19:47:56 2014 Laurent Fourrier
*/

#include <tlist.h>
#include "list_lemin.h"

char		tl_room_exists(t_list *list, char *name)
{
  char		rtn;

  void		tl_room_it(void *ptr)
  {
    char	*room_name;

    room_name = ptr;
    if (strcmp(room_name, name) == 0)
      rtn = 1;
  }
  rtn = 0;
  tl_iterate(list, &tl_room_it);
  return (rtn);
}

/*
** get_room.c for lemin in /home/fourri_l/Projects/repo-lemin
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May  3 17:30:10 2014 Laurent Fourrier
** Last update Sat May  3 19:07:32 2014 Laurent Fourrier
*/

#include <stddef.h>
#include <string.h>
#include "list_lemin.h"

t_room		*get_room(t_lemin *lemin, char *name)
{
  t_room	*room;

  room = lemin->list;
  while (room)
    {
      if (strcmp(room->name, name) == 0)
	return (room);
      room = room->next;
    }
  return (NULL);
}

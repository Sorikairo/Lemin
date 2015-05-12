/*
** add_new_list.c for lemin in /home/fouhet_k/Perso/lemin/src
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Thu Apr 24 11:04:05 2014 Kevin Fouhety
** Last update Fri May  2 12:56:30 2014 Kevin Fouhety
*/

#include "list_lemin.h"

int	size_of_name(char *name)
{
  int	i;

  i = 0;
  while (name[i] != '\0' && name[i] != ' ')
    i++;
  return (i);
}

char	*take_the_name(char *name)
{
  int	i;
  char	*ret;

  ret = x_malloc(size_of_name(name) + 1);
  i = 0;
  while (name[i] != '\0' && name[i] != ' ')
    {
      ret[i] = name[i];
      i++;
    }
  ret[i] = '\0';
  return (ret);
}

void            add_new_list(t_room **list, char *str, char *line)
{
  t_room        *elem;

  if ((elem = malloc(sizeof (t_room))) == NULL)
    exit(0);
  elem->name = take_the_name(line);
  elem->link = take_link(str, elem->name);
  elem->next = *list;
  *list = elem;
}


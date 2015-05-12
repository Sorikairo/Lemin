/*
** init_struct.c for lemin in /home/fouhet_k/Perso/lemin/src
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Thu Apr 24 11:31:55 2014 Kevin Fouhety
** Last update Fri May  2 12:56:47 2014 Kevin Fouhety
*/

#include "list_lemin.h"

t_lemin		*init_struct(char *str, char *first_line)
{
  t_lemin	*lem;

  if ((lem = malloc (sizeof (t_lemin))) == NULL)
    exit (0);
  lem->nbr_ant = take_buffer(first_line);
  lem->start = NULL;
  lem->end = NULL;
  if ((lem->list = malloc (sizeof (t_room))) == NULL)
    exit (0);
  lem->list->next = NULL;
  lem->str = take_buffer(str);
  free(str);
  return (lem);
}

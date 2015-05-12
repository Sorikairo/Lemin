/*
** get_path_list.c for lemin in /home/fourri_l/Projects/repo-lemin
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Fri May  2 15:51:27 2014 Laurent Fourrier
** Last update Sat May  3 19:36:38 2014 Laurent Fourrier
*/

#include <stddef.h>
#include <tlist.h>
#include "solve_lemin.h"

t_list		*get_path_list(t_lemin *lemin)
{
  t_list	*rtn;

  rtn = tl_add(NULL, tl_add(NULL, strdup(lemin->start)));
  return (compute_paths(lemin, rtn, NULL, NULL));
}

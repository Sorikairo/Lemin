/*
** tl_get_last_node.c for lemin in /home/fourri_l/Projects/repo-lemin
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sat May  3 16:25:15 2014 Laurent Fourrier
** Last update Sun May  4 13:32:05 2014 Laurent Fourrier
*/

#include <stddef.h>
#include <tlist.h>

char	*tl_get_last_node(t_list *list)
{
  char	*rtn;

  void	tl_lastnode_it(void *data)
  {
    rtn = data;
  }
  rtn = NULL;
  tl_iterate(list, &tl_lastnode_it);
  return (rtn);
}

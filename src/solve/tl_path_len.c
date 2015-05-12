/*
** tl_path_len.c for lemin in /home/cruvei_t/repo-lemin/src/solve
** 
** Made by Thomas Cruveilher
** Login   <cruvei_t@epitech.net>
** 
** Started on  Sat May  3 16:08:05 2014 Thomas Cruveilher
** Last update Sun May  4 11:27:00 2014 Laurent Fourrier
*/

#include <stddef.h>
#include <tlist.h>

int	tl_path_len(t_list *path)
{
  t_list	*tmp;
  int		len;

  len = 0;
  tmp = path;
  while (tmp != NULL)
    {
      tmp = tmp->next;
      len++;
    }
  return (len);
}

t_list	*tl_get_shortest_path(t_list *path_list)
{
  int		shortest_len;
  t_list	*shortest_path;
  t_list	*tmp;

  shortest_len = 0;
  tmp = path_list;
  while (tmp != NULL)
    {
      if (shortest_len == 0)
	{
	  shortest_len = tl_path_len(tmp->data);
	  shortest_path = tmp->data;
	}
      else
	if (shortest_len > tl_path_len(tmp->data))
	  {
	    shortest_len = tl_path_len(tmp->data);
	    shortest_path = tmp->data;
	  }
      tmp = tmp->next;
    }
  return (shortest_path);
}

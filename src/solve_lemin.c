/*
** solve_lemin.c for lemin in /home/fourri_l/Projects/lemin
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Wed Apr 30 15:51:50 2014 Laurent Fourrier
** Last update Sun May  4 14:08:01 2014 Laurent Fourrier
*/

#include <tlist.h>
#include "list_lemin.h"
#include "solve_lemin.h"

void		solve_lemin(t_lemin *lemin)
{
  t_list	*path_list;

  printf("%s", lemin->str);
  path_list = get_path_list(lemin);
  if (path_list)
    {
      path_list = tl_get_shortest_path(path_list);
      path_list = path_list->next;
      if (path_list)
	print_solution(path_list, atoi(lemin->nbr_ant));
      else
	printf("Error: what the fuck happened\n");
    }
  else
    printf("Error: unsolvable\n");
}

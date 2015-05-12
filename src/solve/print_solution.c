/*
** print_solution.c for lemin in /home/fourri_l/Projects/repo-lemin
** 
** Made by Laurent Fourrier
** Login   <fourri_l@epitech.net>
** 
** Started on  Sun May  4 11:43:28 2014 Laurent Fourrier
** Last update Sun May  4 12:27:16 2014 Laurent Fourrier
*/

#include <string.h>
#include "solve_lemin.h"

static char	print_for_ant(t_list *sol, int ant, int max)
{
  char		rtn;
  char		*room;

  rtn = 0;
  while (sol)
    {
      room = sol->data;
      if (ant > 0 && ant <= max)
	{
	  printf("P%d-%s ", ant, room);
	  rtn = 1;
	}
      sol = sol->next;
      ant--;
    }
  if (rtn)
    printf("\n");
  return (rtn);
}

void		print_solution(t_list *sol, int ants)
{
  int		it;

  it = 1;
  while (print_for_ant(sol, it++, ants));
}

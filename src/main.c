/*
** main.c for lemin in /home/fouhet_k/Perso/lemin/src
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Wed Apr 23 15:06:20 2014 Kevin Fouhety
** Last update Thu Apr 24 12:26:34 2014 Kevin Fouhety
*/

#include "read_lemin.h"

void	check_if_ok()
{
  char	*str;

  str = read_entry();
  if (check_side(str) == -1)
    {
      free (str);
      return ;
    }
  work_on_list(str);
}

int	main()
{
  check_if_ok();
  return (0);
}

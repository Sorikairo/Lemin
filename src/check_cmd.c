/*
** check_cmd.c for lemin in /home/fouhet_k/Perso/lemin/src
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Wed Apr 23 17:13:33 2014 Kevin Fouhety
** Last update Sun Apr 27 10:32:26 2014 Kevin Fouhety
*/

#include "read_lemin.h"

int	my_comp_lemin(char *str, int pos, char *comp)
{
  int	n;

  n = 0;
  while (comp[n] != '\0')
    {
      if (comp[n] != str[pos + n])
	return (-1);
      n++;
   } 
  if (str[pos + n] == '\n' || str[pos + n] == '\0')
    return (1);
  return (-1);
}

int     check_cmd(char *str, int pos)
{
  if (my_comp_lemin(str, pos, "start") == 1)
    return (1);
  if (my_comp_lemin(str, pos, "end") == 1)
    return (1);
  return (-1);
}

/*
** check_side.c for lemin in /home/fouhet_k/Perso/lemin/src
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Wed Apr 23 17:14:14 2014 Kevin Fouhety
** Last update Thu Apr 24 12:13:26 2014 Kevin Fouhety
*/

#include "read_lemin.h"

int	check_both_side(int start, int end)
{
  if (start == 1 && end == 1)
    return (1);
  else if (start == 0 && end == 1)
    printf("No \"start\" room\n");
  else if (start == 1 && end == 0)
    printf("No \"end\" room\n");
  else if (start > 1)
    printf("To many \"start\" room\n");
  else if (end > 1)
    printf("To many \"end\" room\n");
  else if (end > 1 && start > 1)
    printf("To many \"start\" and \"end\" room\n");
  else
    printf("No \"start\" and \"end\"\n");
  return (-1);
}

int	check_side(char *str)
{
  int   i;
  int   end;
  int   start;

  end = 0;
  start = 0;
  i = 0;
  if (str == NULL)
    return ((check_both_side(start, end)));
  while (str[i] != '\0')
    {
      if (str[i] == '#' && str[i + 1] == '#')
        {
          if (my_comp_lemin(str, (i + 2), "start") == 1)
            start++;
          if (my_comp_lemin(str, (i + 2), "end") == 1)
            end++;
        }
      i++;
    }
  return ((check_both_side(start, end)));
}

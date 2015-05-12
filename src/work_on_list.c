/*
** work_on_list.c for lemin in /home/fouhet_k/Perso/lemin/src
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Wed Apr 23 17:30:28 2014 Kevin Fouhety
** Last update Fri May  2 16:31:44 2014 Kevin Fouhety
*/

#include "list_lemin.h"
#include "solve_lemin.h"

int		check_if_nbr(char *line)
{
  int		i;

  i = 0;
  if (line == NULL)
    {
      free (line);
      printf("no number of ant\n");
      return (-1);
    }
  while (line[i] != '\0')
    {
      if (line[i] < '0' || line[i] > '9')
	{
	  printf("not a valid number of ant\n");
	  return (-1);
	}
      i++;
    }
  return (1);
}

int	size_of_line(char *str, int i)
{
  int	ct;

  ct = i;
  while (str[ct] != '\n' && str[ct] != '\0')
    ct++;
  return ((ct - i));
}

static char	*take_next_line(char *str)
{
  static int	i = 0;
  char		*ret;
  int		n;

  n = 0;
  if (str[i] == '\0' || str[i] == '\n')
    return (NULL);
  ret = x_malloc(size_of_line(str, i) + 1);
  while (str[i] != '\n' && str[i] != '\0' && str[i])
    {
      ret[n] = str[i++];
      n++;
    }
  ret[n] = '\0';
  if (str[i] == '\n')
    i++;
  return (ret);
}

void    check_on_list(char *line, t_lemin *lemin)
{
  char  *tmp;

  tmp = line;
  while (tmp != NULL)
    {
      if (my_comp_lemin(tmp, 2, "start") == 1)
        {
          free(tmp);
          lemin->start = take_the_name((tmp = epur_line(take_next_line
							(lemin->str))));
        }
      else if (my_comp_lemin(tmp, 2, "end") == 1)
        {
          free(tmp);
          lemin->end = take_the_name((tmp = epur_line(take_next_line
						      (lemin->str))));
        }
      if (tmp != NULL && is_linking_line(tmp) == -1)
        add_new_list(&(lemin->list), lemin->str, tmp);
      free (tmp);
      tmp = epur_line(take_next_line(lemin->str));
    }
  free(tmp);
}

void		work_on_list(char *str)
{
  t_lemin	*lemin;
  char		*line;

  line = epur_line(take_next_line(str));
  if (check_if_nbr(line) == -1)
    return ;
  lemin = init_struct(str, line);
  free(line);
  line = epur_line(take_next_line(lemin->str));
  check_on_list(line, lemin);
  if (lemin->start && lemin->end)
    solve_lemin(lemin);
  destroy_struct(lemin);
}

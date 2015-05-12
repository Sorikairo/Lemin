/*
** link_utl.c for lemin in /home/fouhet_k/Perso/lemin/src
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Sun Apr 27 16:28:09 2014 Kevin Fouhety
** Last update Fri May  2 12:57:09 2014 Kevin Fouhety
*/

#include "list_lemin.h"

int     is_linking_line(char *line)
{
  int   i;
  int   n;

  n = 0;
  i = 0;
  while (line[i] != '\0')
    {
      if (line[i] == '-')
        n++;
      i++;
    }
  if (n == 0)
    return (-1);
  else if (n > 1)
    exit (printf("Error, linking line not right\n"));
  else
    return (1);
}

int     number_link(char *str, char *name)
{
  int   i;
  int   n;

  n = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (my_comp_link(str, i, name) == 1)
        n++;
      i++;
    }
  return (n);
}

char	*epur_line_link(char *line)
{
  int	i;
  char	*ret;
  int	n;

  n = 0;
  i = 0;
  ret = x_malloc(strlen(line));
  while (line[i + n] != '\0')
    {
      while (line[i + n] == '\t' || line[i + n] == ' ')
	i++;
      ret[n] = line[i + n];
      if (line[i + n] != '\0')
	n++;
    }
  ret[n] = '\0';
  free (line);
  return (ret);
}

char	*epur_line(char *line)
{
  int	i;
  int	n;
  char	*ret;

  i = 0;
  n = 0;
  if (line == NULL)
    return (NULL);
  ret = x_malloc(strlen(line));
  while (line[i] == ' ' || line[i] == '\t')
    i++;
  while (line[i + n] != '\0')
    {
      while (line[i + n] != '\0' && (line[i + n] == ' ' || line[i + n] == '\t')
	     && (line[i + n + 1] == ' ' || line[i + n + 1] == '\t'))
	i++;
      ret[n] = line[i + n];
      if (line[i + n] != '\0')
	n++;
    }
  ret[n] = '\0';
  free (line);
  return (ret);
}

void            destroy_struct(t_lemin *lemin)
{
  int           i;
  t_room        *tmp;

  free(lemin->str);
  free(lemin->nbr_ant);
  free(lemin->start);
  free(lemin->end);
  while (lemin->list->next != NULL)
    {
      i = 0;
      tmp = lemin->list;
      lemin->list = lemin->list->next;
      free(tmp->name);
      while (tmp->link[i] != NULL)
        free(tmp->link[i++]);
      free(tmp->link[i]);
      free(tmp->link);
      free(tmp);
    }
  free(lemin->list);
  free(lemin);
}

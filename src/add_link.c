/*
** add_link.c for lemin in /home/fouhet_k/Perso/lemin/src
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Thu Apr 24 11:15:07 2014 Kevin Fouhety
** Last update Mon Apr 28 17:24:07 2014 deffontaine kevin
*/

#include "list_lemin.h"

static char	*take_next_line(char *str)
{
  static int    i = 0;
  char          *ret;
  int           n;

  n = 0;
  if (str[i] == '\0' || str[i] == '\n')
    {
      i = 0;
      return (NULL);
    }
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

int	my_comp_link(char *str, int pos, char *name)
{
  int   n;

  n = 0;
  while (name[n] != '\0' && str[pos + n] != '\0')
    {
      if (name[n] != str[pos + n])
        return (-1);
      n++;
    }
  if ((str[pos + n] == '\n' || str[pos + n] == '\0' || str[pos + n] == '-') &&
      ((pos > 0 && (str[pos - 1] == '\n' || str[pos - 1] == '-')) || pos == 0))
    return (1);
  return (-1);
}

int	is_our_linking(char *line, char *name)
{
  int	i;

  i = 0;
  while (line[i] != '\0')
    {
      if (my_comp_link(line, i, name) == 1)
	return (1);
      i++;
    }
  return (-1);
}

char	*take_name_linking(char *line, char *name)
{
  int	i;
  char	*ret;
  int	n;

  n = 0;
  i = 0;
  if (my_comp_link(line, 0, name) == 1)
    while (line[i] != '-' && line[i] != '\0')
      i++;
  if (line[i] == '-')
    i++;
  while (line[i + n] != '\0' && line[i + n] != '-')
    n++;
  ret = x_malloc(n + 1);
  n = 0;
  while (line[i + n] != '-' && line[i + n] != '\0')
    {
      ret[n] = line[i + n];
      n++;
    }
  ret[n] = '\0';
  return (ret);
}

char	**take_link(char *str, char *name)
{
  char	**link;
  char	*line;
  int	i;

  i = 0;
  if ((link = malloc((number_link(str, name) + 1) * sizeof (char *))) == NULL)
    exit (printf("ERROR MALLOC\n"));
  line = take_next_line(str);
  while (line)
    {
      if (is_linking_line(line) == 1)
	{
	  if (is_our_linking(line, name) == 1)
	    {
	      line = epur_line_link(line);
	      link[i] = take_name_linking(line, name);
	      i++;
	    }
	}
      free (line);
      line = take_next_line(str);
    }
  link[i] = NULL;
  return (link);
}

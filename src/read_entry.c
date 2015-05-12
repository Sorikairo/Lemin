/*
** read_entry.c for lemin in /home/fouhet_k/Perso/lemin/src
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Wed Apr 23 12:49:41 2014 Kevin Fouhety
** Last update Fri May  2 16:41:12 2014 Kevin Fouhety
*/

#include "read_lemin.h"

char	*put_z(char *ret, int pos)
{
  ret[pos] = '\0';
  return (ret);
}

int	go_to_nextline(char *str, int i)
{
  int	n;

  n = i;
  while (str[n] != '\n' && str[n] != '\0')
    n++;
  n++;
  return (n);
}

char	*put_error(char *ret, int pos, char *str)
{
  int	i;
  int	n;

  i = 0;
  n = 1;
  ret = put_z(ret, pos);
  while (i <= pos)
    {
      if (str[i] == '\n')
	n++;
      i++;
    }
  if (n > 1)
    n++;
  printf("Error input line %d\n", n);
  return (ret);
}

char	*take_valid_cmd(char *str)
{
  int	i;
  char	*ret;
  int	n;

  n = 0;
  i = 0;
  ret = x_malloc(strlen(str) + 1);
  while (str[i] != '\0')
    {
      if (str[i] == '\0' || (str[i] == '\n' && str[i + 1] == '\n'))
	return ((put_error(ret, n, str)));
      if (str[i] == '#')
	if ((str[i] == '#' && str[i + 1] != '#' && i > 0 && str[i - 1] != '#') ||
	    (str[i + 1] == '#' && (check_cmd(str, (i + 2))) == -1))
	  i = go_to_nextline(str, i);
      ret[n] = str[i++];
      n++;
    }
  ret[n] = '\0';
  free(str);
  return (ret);
}

char    *read_entry()
{
  int   ret;
  char  buffer[NB_READ];
  char  *str;

  str = NULL;
  while ((ret = read(0, buffer, (NB_READ - 1))))
    {
      buffer[ret] = '\0';
      str = strcat_lemin(str, buffer);
    }
  if (str != NULL)
    str = take_valid_cmd(str);
  return (str);
}

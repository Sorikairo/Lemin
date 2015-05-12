/*
** strcat_lemin.c for lemin in /home/fouhet_k/Perso/lemin/src
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Wed Apr 23 15:08:12 2014 Kevin Fouhety
** Last update Sun Apr 27 11:49:34 2014 Kevin Fouhety
*/

#include "read_lemin.h"

char	*x_malloc(int size)
{
  char	*ret;

  if ((ret = malloc (size + 1)) == NULL)
    {
      printf("Error Malloc\n");
      exit (-1);
    }
  return (ret);
}

char	*take_buffer(char *buffer)
{
  int	i;
  char	*ret;

  if (buffer == NULL)
    return (NULL);
  i = 0;
  ret = x_malloc(strlen(buffer) + 1);
  while (buffer[i] != '\0')
    {
      ret[i] = buffer[i];
      i++;
    }
  ret = put_z(ret, i);
  return (ret);
}

char	*strcat_lemin(char *str, char *buffer)
{
  char	*ret;
  int	i;
  int	n;

  n = 0;
  i = 0;
  if (str == NULL)
    ret = take_buffer(buffer);
  else
    {
      ret = x_malloc((strlen(buffer) + strlen(str) + 1));
      while (str[i] != '\0')
	{
	  ret[i] = str[i];
	  i++;
	}
      while (buffer[n] != '\0')
	{
	  ret[i + n] = buffer[n];
	  n++;
	}
      free (str);
      ret = put_z(ret, (i + n));
    }
  return (ret);
}

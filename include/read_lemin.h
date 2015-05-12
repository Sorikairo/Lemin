/*
** read_lemin.h for lemin in /home/fouhet_k/Perso/lemin/header
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Wed Apr 23 13:12:15 2014 Kevin Fouhety
** Last update Wed Apr 23 17:31:34 2014 Kevin Fouhety
*/

#ifndef READ_LEMIN_H_
# define READ_LEMIN_H_

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

#define NB_READ 1024

/* read fd 0 */

char	*read_entry();
char	*strcat_lemin(char *, char *);
int	my_comp_lemin(char *, int, char *);

/* list */

void	work_on_list(char *);

/* check */

int	check_cmd(char *, int);
int	check_side(char *);

/* utl */

char	*x_malloc(int);
char	*put_z(char *, int);

#endif

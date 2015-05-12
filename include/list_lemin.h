/*
** list_lemin.h for lemin in /home/fouhet_k/Perso/lemin/header
** 
** Made by Kevin Fouhety
** Login   <fouhet_k@epitech.net>
** 
** Started on  Wed Apr 23 17:32:23 2014 Kevin Fouhety
** Last update Sat May  3 17:29:38 2014 Laurent Fourrier
*/

#ifndef LIST_LEMIN_H_
# define LIST_LEMIN_H_

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_room
{
  char		*name;
  char		**link;
  struct s_room	*next;
}t_room;

typedef struct s_lemin
{
  char		*nbr_ant;
  char		*start;
  char		*end;
  char		*str;
  t_room	*list;
}t_lemin;

/* list */

void	add_new_list(t_room **, char *, char *);
void	check_on_list(char *, t_lemin *);
void	destroy_struct(t_lemin *);

/* line */

int	size_of_line(char *, int);

/* link */

int	number_link(char *, char *);
int	my_comp_link(char *, int, char *);
int	is_linking_line(char *);
int	number_ok_link(char *, char *);
char	**take_link(char *, char *);

/* utils */

int	my_comp_lemin(char *, int, char *);
char	*x_malloc(int);
t_lemin	*init_struct(char *, char *);
char	*take_buffer(char *);
char	*take_the_name(char *);
char	*epur_line_link(char *);
char	*epur_line(char *);

/* used by the solver */
t_room	*get_room(t_lemin *lemin, char *name);

#endif

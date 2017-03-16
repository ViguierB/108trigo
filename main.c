/*
** main.c for math in /home/benji_epitech/Maths/108trigo
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Mar 14 13:16:37 2017 Benjamin Viguier
** Last update Thu Mar 16 13:20:15 2017 Benjamin Viguier
*/

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "trigo.h"

t_fct	g_fct_tab[] =
  {
    {"EXP", &my_exp},
    {"COS", &my_cos},
    {"SIN", &my_sin},
    {"COSH", &my_cosh},
    {"SINH", &my_sinh},
    {"-h", &help},
    {"--help", &help},
    {NULL, &help}
  };

int		fill_matrix(t_matrix *m, int ac, char **av)
{
  int		len;
  double	*ptr;

  m->s = sqrt(ac);
  m->s += (m->s * m->s != ac);
  len = m->s * m->s;
  if (len != ac)
    return (-1);
  m->buf = malloc(sizeof(double) * len);
  if (m->buf == NULL)
    return (-1);
  memset(m->buf, 0, sizeof(double) * len);
  ptr = m->buf;
  while (ac)
    {
      *(ptr++) = atof(*(av++));
      ac--;
    }
  return (0);
}

int	print_matrix(t_matrix *m)
{
  int	i;

  i = 0;
  while (i < m->s * m->s)
    {
      printf("%.2lf%s", m->buf[i],
	     ((i + 1) % m->s) ? "\t" : "\n");
      i++;
    }
  return (0);
}

int		main(int ac, char **av)
{
  t_matrix	m;
  t_matrix	*res;
  int		i;

  if (ac < 1)
    g_my_name = "./108trigo";
  else
    g_my_name = av[0];
  if (ac < 2)
    {     
      help(NULL);
      return (84);
    }
  else
    {
      res = NULL;
      if (fill_matrix(&m, ac - 2, av + 2) < 0)
        return (84);
      i = 0;
      while (g_fct_tab[i].str)
	{
	  if (!strcmp(g_fct_tab[i].str, av[1]))
	    {
	      if (m.s == 0)
		return (84);
	      res = (g_fct_tab[i].fct)(&m);
	      break;
	    }
	  i++;
	}
      if (g_fct_tab[i].str == NULL)
	      {
          (g_fct_tab[i].fct)(NULL);
          return (84);
        }
      if (res)
	    print_matrix(res);
  }
  return (0);
}

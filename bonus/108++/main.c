/*
** main.c for math in /home/benji_epitech/Maths/108trigo
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Mar 14 13:16:37 2017 Benjamin Viguier
** Last update Thu Mar 16 09:53:53 2017 Benjamin Viguier
*/

#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "trigo.h"

int   g_aff_all = 0;
int   g_isacos = 0;

t_fct	g_fct_tab[] =
  {
    {"EXP", &my_exp},
    {"COS", &my_cos},
    {"SIN", &my_sin},
    {"TAN", &my_tan},
    {"COSH", &my_cosh},
    {"SINH", &my_sinh},
    {"ACOS", &my_acos},
    {"ASIN", &my_asin},
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

int	        print_matrix(t_matrix *m)
{
  int	      i;
  t_matrix  tmp;

  i = 0;
  if (g_isacos)
  {
    cpy_matrix(&tmp, m);
    invssub_matrix(&tmp, M_PI / 2.0);
    m = &tmp;
  }
  while (i < m->s * m->s)
    {
      if (g_aff_all)
        printf("%lf%s", m->buf[i], ((i + 1) % m->s) ? "\t" : "\n");
      else
        printf("%.2lf%s", m->buf[i], ((i + 1) % m->s) ? "\t" : "\n");
      i++;
    }
  if (g_isacos)
    free(tmp.buf);
  return (0);
}

char	*upper(char *str)
{
  char	*res;

  res = str;
  while (*res)
    {
      if (*res >= 'a' && *res <= 'z')
	      *res += 'A' - 'a';
      res++;
    }
  return (str);
}

int   get_params(char *av, int *ev)
{
  if (*av != '-')
    return (0);
  else
    av++;
  while (*av)
  {
    if (*av == 'a')
      g_aff_all = 1;
    if (*av == 'e')
      *ev = 1;
    av++;
  }
  return (1);
}

int		main(int ac, char **av)
{
  t_matrix	m;
  t_matrix	*res;
  int		i;
  int		ev;
  int   add = 0;

  ev = 0;
  if (ac < 1)
    g_my_name = "./108trigo";
  else
    g_my_name = av[0];
  if (ac < 2)
  {     
    help(NULL, 0);
    return (84);
  }
  else
  {
    add = get_params(av[1], &ev);
    res = NULL;
    fill_matrix(&m, ac - (2 + add), av + (2 + add));
    i = 0;
    while (g_fct_tab[i].str)
	  {
	    if (!strcmp(g_fct_tab[i].str, upper(av[1 + add])))
	    {
	      res = (g_fct_tab[i].fct)(&m, ev);
	      break;
	    }
      i++;
    }
    if (g_fct_tab[i].str == NULL)
	    (g_fct_tab[i].fct)(NULL, 0);
    if (res)
    {
      if (ev)
        printf("Result :\n");
	    print_matrix(res);
      free(res->buf);
      free(res);
    }
    free(m.buf);
  }
}

/*
** matrix.c for math in /home/benji_epitech/Maths/108trigo
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Mar 15 14:25:41 2017 Benjamin Viguier
** Last update Wed Mar 15 20:00:04 2017 Benjamin Viguier
*/

#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "trigo.h"

int	get_imatrix(t_matrix *dest, int s) 
{
  int	i, j;

  dest->s = s;
  dest->buf = malloc(sizeof(double) * dest->s * dest->s);
  for (i = 0; i < s; i++)
    for (j = 0; j < s; j++)
      if (i == j)
	      dest->buf[i * s + j] = 1;
      else
	      dest->buf[i * s + j] = 0;
  return (0);
}

int	cpy_matrix(t_matrix *dest, t_matrix *from)
{
  dest->s = from->s;
  dest->buf = malloc(sizeof(double) * dest->s * dest->s);
  memcpy(dest->buf, from->buf, sizeof(double) * dest->s * dest->s);
  return (0);
}

int		mult_matrix(t_matrix *a, t_matrix *b)
{
  double	*dest;
  int		i, j, k;
  
  dest = malloc(sizeof(double) * a->s * a->s);
  for (i = 0; i < a->s; i++)
    for (j = 0; j < a->s; j++)
      for (k = 0; k < a->s; k++)
	      dest[i * a->s + j] += a->buf[i * a->s + k] * b->buf[k * a->s + j];
  free(a->buf);
  a->buf = dest;
  return (0);
}

int	mul_matrix(t_matrix *a, double b)
{
  int		i, j;

  for (i = 0; i < a->s; i++)
    for (j = 0; j < a->s; j++)
      a->buf[i * a->s +j] *= b;
  return (0);
}

int	add_matrix(t_matrix *a, t_matrix *b)
{  
  int		i, j;

  for (i = 0; i < a->s; i++)
    for (j = 0; j < a->s; j++)
      a->buf[i * a->s +j] += b->buf[i * a->s + j];
  return (0);
}

int	sub_matrix(t_matrix *a, t_matrix *b)
{  
  int		i, j;

  for (i = 0; i < a->s; i++)
    for (j = 0; j < a->s; j++)
      a->buf[i * a->s +j] -= b->buf[i * a->s + j];
  return (0);
}

int	ssub_matrix(t_matrix *a, double b)
{
  int		i, j;

  for (i = 0; i < a->s; i++)
    for (j = 0; j < a->s; j++)
      a->buf[i * a->s +j] -= b;
  return (0);
}

int	invssub_matrix(t_matrix *a, double b)
{
  int		i, j;

  for (i = 0; i < a->s; i++)
    for (j = 0; j < a->s; j++)
      a->buf[i * a->s +j] = b - a->buf[i * a->s +j];
  return (0);
}

int	div_matrix(t_matrix *a, double b)
{
  int		i, j;

  for (i = 0; i < a->s; i++)
    for (j = 0; j < a->s; j++)
      a->buf[i * a->s +j] /= b;
  return (0);
}

int is_mequal(t_matrix *m, t_matrix *tmp)
{
  int i, j;

  for (i = 0; i < m->s; i++)
    for (j = 0; j < m->s; j++)
      if (m->buf[i * m->s + j] != tmp->buf[i * m->s + j])
        return (0);
  return (1);
}

int  is_mnan(t_matrix *m)
{
  int i, j;

  for (i = 0; i < m->s; i++)
    for (j = 0; j < m->s; j++)
      if (isnan(m->buf[i * m->s + j]))
        return (1);
  return (0);
}

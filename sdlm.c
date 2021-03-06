/*
** sdlm.c for matj in /home/benji_epitech/Maths/108trigo
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Wed Mar 15 14:04:31 2017 Benjamin Viguier
** Last update Thu Mar 16 11:16:19 2017 Benjamin Viguier
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "trigo.h"

char	*g_my_name;

t_matrix	*my_exp(t_matrix *m)
{
  t_matrix	*res;
  t_matrix	x;
  t_matrix	tmp;
  t_matrix  last;
  double	fac = 1;
  int		i = 2;
  
  clock_t	start = clock();
  clock_t	now = start;

  res = malloc(sizeof(t_matrix));
  cpy_matrix(&x, m);
  get_imatrix(res, m->s);
  add_matrix(res, m);
  while (i < PRECI && (now - start) < TIMEOUT)
    {
      cpy_matrix(&last, res);
      mult_matrix(&x, m);
      fac *= i;
      cpy_matrix(&tmp, &x);
      div_matrix(&tmp, fac);
      add_matrix(res, &tmp);
      free(tmp.buf);
      now = clock();
      if (is_mequal(res, &last))
        break;
      if (is_mnan(res))
      {
        cpy_matrix(res, &last);
        break;        
      }
      i++;
    }
  free(x.buf);
  free(last.buf);
  return (res);
}

t_matrix	*my_cos(t_matrix *m)
{
  t_matrix	*res;
  t_matrix	x;
  t_matrix	tmp;
  t_matrix  last;
  double	fac = 2;
  int		i = 2;
  int		j = 2;
  
  clock_t	start = clock();
  clock_t	now = start;

  res = malloc(sizeof(t_matrix));
  cpy_matrix(&x, m);
  get_imatrix(res, m->s);
  while (i < PRECI && (now - start) < TIMEOUT)
  {
      cpy_matrix(&last, res);
      mult_matrix(&x, m);
      cpy_matrix(&tmp, &x);
      div_matrix(&tmp, fac);
      if (i % 2)
	      add_matrix(res, &tmp);
      else
	      sub_matrix(res, &tmp);
      free(tmp.buf);
      mult_matrix(&x, m);
      i++;
      fac *= ++j;
      fac *= ++j;
      now = clock();
      if (is_mequal(res, &last))
        break;
      if (is_mnan(res))
      {
        cpy_matrix(res, &last);
        break;        
      }
  }
  free(last.buf);
  free(x.buf);
  return (res);
}

t_matrix	*my_sin(t_matrix *m)
{
  t_matrix	*res;
  t_matrix	x;
  t_matrix	tmp;
  t_matrix  last;
  double	fac = 6;
  int		i = 2;
  int		j = 3;
  clock_t	start = clock();
  clock_t	now = start;

  res = malloc(sizeof(t_matrix));
  cpy_matrix(&x, m);
  cpy_matrix(res, m);
  while (i < PRECI && (now - start) < TIMEOUT)
    {
      cpy_matrix(&last, res);
      mult_matrix(&x, m);
      mult_matrix(&x, m);
      cpy_matrix(&tmp, &x);
      div_matrix(&tmp, fac);
      if (i % 2)
	      add_matrix(res, &tmp);
      else
	      sub_matrix(res, &tmp);
      free(tmp.buf);
      i++;
      fac *= ++j;
      fac *= ++j;
      now = clock();
      if (is_mequal(res, &last))
        break;
      if (is_mnan(res))
      {
        cpy_matrix(res, &last);
        break;        
      }
    }
  free(x.buf);
  return (res);
}

t_matrix	*my_sinh(t_matrix *m)
{
  t_matrix	*res;
  t_matrix	x;
  t_matrix	tmp;
  t_matrix  last;
  double	fac = 6;
  int		i = 2;
  int		j = 3;
    
  clock_t	start = clock();
  clock_t	now = start;

  res = malloc(sizeof(t_matrix));
  cpy_matrix(&x, m);
  cpy_matrix(res, m);
  while (i < PRECI && (now - start) < TIMEOUT)
    {
      cpy_matrix(&last, res);
      mult_matrix(&x, m);
      mult_matrix(&x, m);
      cpy_matrix(&tmp, &x);
      div_matrix(&tmp, fac);
      add_matrix(res, &tmp);
      free(tmp.buf);
      i++;
      fac *= ++j;
      fac *= ++j;
      now = clock();
      if (is_mequal(res, &last))
        break;
      if (is_mnan(res))
      {
        cpy_matrix(res, &last);
        break;        
      }
    }
  free(last.buf);
  free(x.buf);
  return (res);
}

t_matrix	*my_cosh(t_matrix *m)
{
  t_matrix	*res;
  t_matrix	x;
  t_matrix	tmp;
  t_matrix  last;
  double	fac = 2;
  int		i = 2;
  int		j = 2;
    
  clock_t	start = clock();
  clock_t	now = start;

  res = malloc(sizeof(t_matrix));
  cpy_matrix(&x, m);
  get_imatrix(res, m->s);
  while (i < PRECI && (now - start) < TIMEOUT)
    {
      cpy_matrix(&last, res);
      mult_matrix(&x, m);
      cpy_matrix(&tmp, &x);
      div_matrix(&tmp, fac);
      add_matrix(res, &tmp);
      free(tmp.buf);
      mult_matrix(&x, m);
      i++;
      fac *= ++j;
      fac *= ++j;
      now = clock();
      if (is_mequal(res, &last))
        break;
      if (is_mnan(res))
      {
        cpy_matrix(res, &last);
        break;        
      }
    }
  free(x.buf);
  return (res);
}

t_matrix	*help(t_matrix *m)
{
  m = (void*) m;

  printf("USAGE\n"
	 "\t%s\t [-e|a] fun a0 a1 a2....\n"
	 "DESCRIPTION\n"
	 "\te\tshow evolution, cycle by cycle\n"
	 "\ta\tshow all\n"
	 "\tfun\tfunction to be applied, among at least ""EXP"", ""COS"", ""SIN"", ""COSH"", ""SINH"", ""ACOS"" and ""ASIN""\n"
	 "\tai\tcoeficients of the matrix\n", g_my_name);
  return (NULL);
}

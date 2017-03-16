/*
** trigo.h for trigo in /home/benji_epitech/Maths/108trigo
** 
** Made by Benjamin Viguier
** Login   <benjamin.viguier@epitech.eu>
** 
** Started on  Tue Mar 14 13:18:15 2017 Benjamin Viguier
** Last update Thu Mar 16 09:54:48 2017 Benjamin Viguier
*/

#ifndef TRISO_H_
# define TRISO_H_ /* lel */

# define TIMEOUT (1000)
# define PRECI (40)

typedef struct	s_matrix
{
  int		s;
  double	*buf;
}		t_matrix;

typedef struct	s_fct
{
  char		*str;
  t_matrix	*(*fct)(t_matrix *, int);
}		t_fct;

extern char *g_my_name;

t_matrix	*my_cos(t_matrix *m, int ev);
t_matrix	*my_sin(t_matrix *m, int ev);
t_matrix	*my_exp(t_matrix *m, int ev);
t_matrix	*my_cosh(t_matrix *m, int ev);
t_matrix	*my_sinh(t_matrix *m, int ev);
t_matrix	*my_acos(t_matrix *m, int ev);
t_matrix	*my_asin(t_matrix *m, int ev);
t_matrix	*help(t_matrix *m, int ev);

int	cpy_matrix(t_matrix *dest, t_matrix *from);
int	mult_matrix(t_matrix *a, t_matrix *b);
int	mul_matrix(t_matrix *a, double b);
int	add_matrix(t_matrix *a, t_matrix *b);
int	sub_matrix(t_matrix *a, t_matrix *b);
int	div_matrix(t_matrix *a, double b);
int	ssub_matrix(t_matrix *a, double b);
int	get_imatrix(t_matrix *dest, int s);
int	print_matrix(t_matrix *m);

#endif /* !TRISO_H_ */

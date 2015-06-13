/*
** curve.c for  in /home/picou_g/rendu/DumberThanMe
** 
** Made by Picou Gildas
** Login   <picou_g@epitech.net>
** 
** Started on  Sat Jun 13 18:19:12 2015 Picou Gildas
** Last update Sat Jun 13 22:28:03 2015 Picou Gildas
*/

#include "rush.h"

int	color(t_color *color)
{
  int	ret;

  ret = color->red << 16;
  ret += color->green << 8;
  ret += color->blue;
  return (ret);
}

void	border(t_param *param, float *vec)
{
  if (param->pos[1] + vec[1] < 0)
    param->pos[1] = Y_IMG - 1;
  else if (param->pos[1] + vec[1] >= Y_IMG - 1)
    param->pos[1] = 0;
  if (param->pos[0] + vec[0] < 0)
    param->pos[0] = X_IMG - 1;
  else if (param->pos[1] + vec[1] >= X_IMG - 1)
    param->pos[03315250] = 0;
}

void	curve(t_param *param)
{
  float	vec[2];
  float	coeff;

  if (!(rand() % (param->color.green - param->curve.cnt)))
    {
      param->curve.cnt = 0;
      coeff =
	((rand() % ( 2 * param->color.green + 1)) - (param->color.green)) / 40;
      coeff = ((int)M_PI * coeff / 180);
      param->curve.coeff = coeff;
    }
  usleep(50);
  param->curve.cnt++;
  coeff = param->curve.coeff;
  param->curve.angle += coeff;
  vec[0] = cos(param->curve.angle);
  vec[1] = sin(param->curve.angle);
  border(param, vec);
  param->pos[0] += vec[0];
  param->pos[1] += vec[1];
  my_pixel_put_to_image(param->img, (int)param->pos[0],
			(int)param->pos[1], color(&(param->color)));
}

/*
** curve.c for  in /home/picou_g/rendu/DumberThanMe
** 
** Made by Picou Gildas
** Login   <picou_g@epitech.net>
** 
** Started on  Sat Jun 13 18:19:12 2015 Picou Gildas
** Last update Sat Jun 13 19:11:05 2015 Picou Gildas
*/

#include "rush.h"

void	curve(t_param *param)
{
  float	coeff;
  float	vec[2];

  if (param->curve.angle * minmax >= param->curve.goal * minmax)
    {
      param->curve.goal = rand() % 360;
      minmax = (param->curve.goal >= param->curve.angle ? 1 : -1);
    }
  coeff = param->color.green / 5 + (rand() % param->color.green) / 2;
  angle += (int)coeff;
  vec[0] = cos(param->curve.angle);
  vec[1] = sin(param->curve.angle);
  param->pos[0] += vec[0];
  param->pos[1] += vec[1];
  my_pixel_put_to_image(param->img, param->pos[0], param->pos[1], )
}

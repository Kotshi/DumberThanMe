/*
** curve.c for  in /home/picou_g/rendu/DumberThanMe
** 
** Made by Picou Gildas
** Login   <picou_g@epitech.net>
** 
** Started on  Sat Jun 13 18:19:12 2015 Picou Gildas
** Last update Sun Jun 14 16:22:00 2015 Picou Gildas
*/

#include "rush.h"

void	border(t_param *param, float *vec)
{
  if (param->pos[1] + vec[1] < 0)
    param->pos[1] = Y_IMG - 1;
  else if (param->pos[1] + vec[1] >= Y_IMG - 1)
    param->pos[1] = 0;
  if (param->pos[0] + vec[0] < 0)
    param->pos[0] = X_IMG - 1;
  else if ((param->pos[0] + vec[0]) >= (X_IMG - 1))
    param->pos[0] = 0;
}

void	curve(t_param *param)
{
  float	vec[2];
  float	coeff;

  if (!(rand() %
	(ABS(param->color.green - param->color.red / 4) - param->curve.cnt)))
    {
      param->curve.cnt = 0;
      coeff =
	((rand() % (2 * param->color.green + 1)) - (param->color.green)) / 40;
      coeff = ((int)M_PI * coeff / 180);
      param->curve.coeff = coeff;
    }
  if (!(rand() % (50 - param->color.red)))
    param->curve.angle = rand() % (int)(2 * M_PI);
  if (param->curve.coeff < param->color.red / 500)
    param->curve.coeff = 0;
  usleep(20 * param->color.green);
  param->curve.cnt++;
  param->curve.coeff += (param->curve.coeff < 0.0001 ? 0.0001 : -0.0001);
  param->curve.angle += param->curve.coeff;
  vec[0] = cos(param->curve.angle);
  vec[1] = sin(param->curve.angle);
  border(param, vec);
  param->pos[0] += vec[0];
  param->pos[1] += vec[1];
  my_pixel_put_to_image(param->img, (int)param->pos[0],
  			(int)param->pos[1], get_color(&(param->color)));
  anti_aliasing(param);
}

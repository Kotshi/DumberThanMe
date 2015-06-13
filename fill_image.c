/*
** fill_image.c for  in /home/donade_f/rendu/semestre_2/rush/rush_mlx
** 
** Made by florian donadei
** Login   <donade_f@epitech.net>
** 
** Started on  Sat Jun 13 15:14:59 2015 florian donadei
** Last update Sat Jun 13 21:56:57 2015 Picou Gildas
*/

#include "rush.h"

void             init(t_param *param)
{
  param->color.red = 50;
  param->curve.coeff = 0.01;
  param->curve.cnt = 0;
  param->curve.max = 100;
  param->color.green = 100;
  param->color.blue = 50;
  param->curve.angle = 0;
  param->pos[0] = X_IMG / 2;
  param->pos[1] = Y_IMG / 2;
}

int		dumb(t_param *param)
{
  mlx_put_image_to_window(param->mlx->ptr, param->mlx->win,
                          param->mlx->img, 0, 0);
}

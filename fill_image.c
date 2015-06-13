/*
** fill_image.c for  in /home/donade_f/rendu/semestre_2/rush/rush_mlx
** 
** Made by florian donadei
** Login   <donade_f@epitech.net>
** 
** Started on  Sat Jun 13 15:14:59 2015 florian donadei
** Last update Sat Jun 13 19:08:36 2015 Picou Gildas
*/

#include "rush.h"

void            change_color(t_img *img, int r, int v, int b)
{
  img->color[0] = r;
  img->color[1] = v;
  img->color[2] = b;
}

void             init(t_param *param)
{
  param->curve.angle = 0;
  param->curve.goal = rand() % 360;
  param->curve.minmax = 1;
  param->pos[0] = X_IMG / 2;
  param->pos[1] = Y_IMG / 2;
}

int		dumb(t_param *param)
{
  mlx_put_image_to_window(param->mlx->ptr, param->mlx->win,
                          param->mlx->img, 0, 0);
}

/*
** fill_image.c for  in /home/donade_f/rendu/semestre_2/rush/rush_mlx
** 
** Made by florian donadei
** Login   <donade_f@epitech.net>
** 
** Started on  Sat Jun 13 15:14:59 2015 florian donadei
** Last update Sat Jun 13 16:24:52 2015 florian donadei
*/

#include "rush.h"

void            change_color(t_img *img, int r, int v, int b)
{
  img->color[0] = r;
  img->color[1] = v;
  img->color[2] = b;
}

void             calc(t_param *param, int x, int y)
{
  t_vector      v1;
  t_coord       p;
  t_eyes	eyes;
  t_color	color;

  p.x = x;
  p.y = y;
  p.z = 0;
  v1.x = 100;                
  v1.y = (X_IMG / 2) - (double)x;
  v1.z = (Y_IMG / 2) - (double)y;
  eyes.x = EYES_X;
  eyes.y = EYES_Y;
  eyes.z = EYES_Z;
  color.red = 50;
  color.green = 150;
  color.blue = 50;
  /* param->p = &p; */
  /* param->v1 = &v1; */
  /* param->eyes = &eyes; */
}

void            fill_image(t_param *param)
{
  int           x;
  int           y;

  y = 0;
  while (y < Y_IMG)
    {
      x = 0;
      while (x < X_IMG)
        {
          change_color(param->img, 0, 0, 0);
          calc(param, x, y);
          mlx_pixel_put_image(param->img, x, y);
          x++;
        }
      y++;
    }
  mlx_put_image_to_window(param->mlx->ptr, param->mlx->win,
                          param->mlx->img, 0, 0);
}

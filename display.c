/*
** display.c for  in /home/donade_f/rendu/semestre_2/rush/rush_mlx
** 
** Made by florian donadei
** Login   <donade_f@epitech.net>
** 
** Started on  Sat Jun 13 15:13:45 2015 florian donadei
** Last update Sat Jun 13 17:54:58 2015 Picou Gildas
*/

#include "rush.h"

int             expose(t_param *param)
{
  mlx_put_image_to_window(param->mlx->ptr, param->mlx->win,
                          param->mlx->img, 0, 0);
  return (0);
}

int             key_hook(int keycode, t_param *param)
{
  if (keycode == 65307)
    {
      mlx_destroy_window(param->mlx->ptr, param->mlx->win);
      exit(0);
    }
  return (0);
}

void            init_mlx(t_mlx *mlx, t_img *img)
{
  if ((mlx->ptr = mlx_init()) == NULL)
    exit(0);
  if ((mlx->win = mlx_new_window(mlx->ptr, X_IMG, Y_IMG, WIN)) == NULL)
    exit(0);
  if ((mlx->img = mlx_new_image(mlx->ptr, X_IMG, Y_IMG)) == NULL)
    exit(0);
  if ((img->data = mlx_get_data_addr(mlx->img, &(img->bpp), &(img->sizeline),
				     &(img->endian))) == NULL)
    exit(0);
}

void            display(t_param *param)
{
  t_mlx         mlx;
  t_img         img;

  param->mlx = &mlx;
  param->img = &img;
  init_mlx(&mlx, &img);
  init(param);
  mlx_key_hook(mlx.win, key_hook, param);
  mlx_expose_hook(mlx.win, &expose, param);
  mlx_loop(mlx.ptr);
}

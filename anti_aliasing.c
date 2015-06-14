/*
** anti_aliasing.c for  in /home/picou_g/rendu/DumberThanMe
** 
** Made by Picou Gildas
** Login   <picou_g@epitech.net>
** 
** Started on  Sun Jun 14 12:32:10 2015 Picou Gildas
** Last update Sun Jun 14 14:31:26 2015 Picou Gildas
*/

#include "rush.h"

void	add_color(int *rgb, int ret, int i)
{
  if (i)
    {
      rgb[0] = 0;
      rgb[1] = 0;
      rgb[2] = 0;
    }
  else
    {
      rgb[0] += ret & 0xFF0000 >> 16;
      rgb[1] += ret & 0x00FF00 >> 8;
      rgb[2] += ret & 0x0000FF;
    }
}

int	avg_color(t_param *param, int *rgb, int amount)
{
  int	color;
  int	ret;

  ret = get_imgpxl(param->img, (int)param->pos[0], (int)param->pos[1]);
  color = (ret & 0xFF0000 / 4 << 16);
  color += (ret & 0x00FF00 / 4 << 8);
  color += (ret & 0x0000FF / 4);
  return (color);
}

int	get_diff(t_param *param, int posX, int posY)
{
  int	rgb[3];
  int	actual[3];
  int	ret;
  int	diff;

  ret = get_imgpxl(param->img, (int)param->pos[0], (int)param->pos[1]);
  rgb[0] = ret & 0xFF0000 >> 16;
  rgb[1] = ret & 0x00FF00 >> 8;
  rgb[2] = ret & 0x0000FF;
  ret = get_imgpxl(param->img, posX, posY);
  actual[0] = ret & 0xFF0000 >> 16;
  actual[1] = ret & 0x00FF00 >> 8;
  actual[2] = ret & 0x0000FF;
  diff = ABS(rgb[0] - actual[0]);
  diff += ABS(rgb[1] - actual[1]);
  diff += ABS(rgb[2] - actual[2]);
  if (diff > 10)
    return (0);
  return (1);
}

int	get_pxl_sample(t_param *param, int posX, int posY)
{
  int	cnt[2];
  int	samples;
  int	ret;
  int	rgb[3];

  if (posX < 0 || posX >= X_IMG || posY < 0 || posY >= Y_IMG ||
      get_diff(param, posX, posY))
    return (-1);
  cnt[0] = -2;
  samples = 0;
  add_color(rgb, ret, 1);
  while (++cnt[0] != 2)
    {
      cnt[1] = -2;
      while (++cnt[1] != 2)
	{
	  if ((ret = get_imgpxl(param->img, posX + cnt[0], posY + cnt[1])) > 0)
	    {
	      samples++;
	      add_color(rgb, ret, 0);
	    }
	}
    }
  return (avg_color(param, rgb, samples));
}

void	anti_aliasing(t_param *param)
{
  int	color[4];

  color[0] = get_pxl_sample(param, (int)param->pos[0] - 1, (int)param->pos[1]);
  color[1] = get_pxl_sample(param, (int)param->pos[0], (int)param->pos[1] - 1);
  color[2] = get_pxl_sample(param, (int)param->pos[0] + 1, (int)param->pos[1]);
  color[3] = get_pxl_sample(param, (int)param->pos[0], (int)param->pos[1] + 1);
  if (color[0] != -1)
    my_pixel_put_to_image
      (param->img, (int)param->pos[0] - 1, (int)param->pos[1], color[0]);
  if (color[1] != -1)
    my_pixel_put_to_image
      (param->img, (int)param->pos[0], (int)param->pos[1] - 1, color[1]);
  if (color[2] != -1)
    my_pixel_put_to_image
      (param->img, (int)param->pos[0] + 1, (int)param->pos[1], color[2]);
  if (color[3] != -1)
    my_pixel_put_to_image
      (param->img, (int)param->pos[0], (int)param->pos[1] + 1, color[3]);
}

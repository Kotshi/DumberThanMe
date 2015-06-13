/*
** my_pixel_put_to_image.c for  in /home/picou_g/Igraph-test/image
** 
** Made by Picou Gildas
** Login   <picou_g@epitech.net>
** 
** Started on  Mon Nov 10 10:58:39 2014 Picou Gildas
** Last update Sat Jun 13 17:49:42 2015 Picou Gildas
*/

#include "rush.h"

int	my_pixel_put_to_image(t_img *img, int posX, int posY, int clr)
{
  int	*ptr;

  ptr = img->data + (int)(img->sizeline * posY + posX * img->bpp / 8);
  if (posY >= 0 && posY < X_IMG)
    *ptr = clr;
  else
    return (1);
  return (0);
}

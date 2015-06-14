/*
** get_color.c for  in /home/donade_f/rendu/semestre_2/rush/DumberThanMe
** 
** Made by florian donadei
** Login   <donade_f@epitech.net>
** 
** Started on  Sat Jun 13 18:05:36 2015 florian donadei
** Last update Sun Jun 14 11:46:58 2015 Picou Gildas
*/

#include "rush.h"

int	get_color(t_color *color)
{
  int	nb;

  nb = (color->red > 255 ? 255 : color->red);
  nb = nb << 8;
  nb += (color->green > 255 ? 255 : color->green);
  nb = nb << 8;
  nb += (color->blue > 255 ? 255 : color->blue);
  return (nb);
}

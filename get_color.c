/*
** get_color.c for  in /home/donade_f/rendu/semestre_2/rush/rush_mlx/DumberThanMe
** 
** Made by florian donadei
** Login   <donade_f@epitech.net>
** 
** Started on  Sat Jun 13 18:05:36 2015 florian donadei
** Last update Sat Jun 13 18:15:48 2015 florian donadei
*/

#include "rush.h"

int	get_color(t_color *color)
{
  int	nb;

  nb = color->red;
  nb = nb << 8;
  nb = color->green;
  nb = nb << 8;
  nb = color->blue;
  return (nb);
}

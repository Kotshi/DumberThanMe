/*
** rush.h for  in /home/donade_f/rendu/semestre_2/rush/rush_mlx
** 
** Made by florian donadei
** Login   <donade_f@epitech.net>
** 
** Started on  Sat Jun 13 15:17:20 2015 florian donadei
** Last update Sat Jun 13 15:48:25 2015 florian donadei
*/

#ifndef DISPLAY_H_
# define DISPLAY_H_

#define X_IMG 1080
#define Y_IMG 700
#define EYES_X 300
#define EYES_Y 0
#define EYES_Z 100

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "minilibx/mlx.h"

typedef struct  s_mlx
{
  void          *ptr;
  void          *win;
  void          *img;
}               t_mlx;

typedef struct  s_img
{
  char          *data;
  int           bpp;
  int           sizeline;
  int           endian;
  int           color[3];
}               t_img;

typedef struct  s_vector
{
  int	x;
  int	y;
  int	z;
}               t_vector;

typedef struct  s_eyes
{
  int	x;
  int	y;
  int	z;
}               t_eyes;

typedef struct  s_color
{
  int	red;
  int	green;
  int	blue;
}               t_color;

typedef struct  s_coord
{
  int	x;
  int	y;
  int	z;
}               t_coord;

typedef struct  s_param
{
  t_mlx         *mlx;
  t_img         *img;
  t_vector      *vector;
  t_eyes	*eyes;
  t_color	*color;
  t_coord	*coord;
}               t_param;

#endif

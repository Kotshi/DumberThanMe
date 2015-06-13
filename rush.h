/*
** rush.h for  in /home/donade_f/rendu/semestre_2/rush/rush_mlx
** 
** Made by florian donadei
** Login   <donade_f@epitech.net>
** 
** Started on  Sat Jun 13 15:17:20 2015 florian donadei
** Last update Sat Jun 13 19:00:33 2015 Picou Gildas
*/

#ifndef RUSH_H_
# define RUSH_H_

#define X_IMG 1080
#define Y_IMG 700
#define WIN "I am not a cube"

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
  void          *data;
  int           bpp;
  int           sizeline;
  int           endian;
  int           color[3];
}               t_img;

typedef struct  s_pos
{
  int		x;
  int		y;
  int		z;
}               t_pos;

typedef struct  s_color
{
  int		red;
  int		green;
  int		blue;
}               t_color;

typedef struct	s_curve
{
  int		angle;
  int		goal;
  int		minsup;
}		t_curve;

typedef struct  s_param
{
  t_mlx         *mlx;
  t_img         *img;
  t_color	color;
  float		pos[2];
  t_curve	curve;
}               t_param;

#endif

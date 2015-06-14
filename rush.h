/*
** rush.h for  in /home/donade_f/rendu/semestre_2/rush/rush_mlx
** 
** Made by florian donadei
** Login   <donade_f@epitech.net>
** 
** Started on  Sat Jun 13 15:17:20 2015 florian donadei
** Last update Sun Jun 14 14:15:03 2015 Picou Gildas
*/

#ifndef RUSH_H_
# define RUSH_H_

#define X_IMG 1080
#define Y_IMG 700
#define WIN "I am not a cube"
#define ABS(value) (value < 0 ? -value : value)

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <mlx.h>

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
  float		coeff;
  float		angle;
  int		cnt;
  int		max;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 15:47:42 by lweglarz          #+#    #+#             */
/*   Updated: 2021/03/09 14:34:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "minirt.h"

typedef struct		s_vector
{
	double			x;
	double			y;
	double			z;
}					t_vector;

typedef	struct		s_px
{
	int				x;
	int				y;
}					t_px;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_frgb
{
	float			r;
	float			g;
	float			b;
}					t_frgb;

typedef struct		s_reso
{
	int				w;
	int				h;
}					t_reso;

typedef struct		s_amli
{
	double			ratio;
	t_rgb			color;
}					t_amli;

typedef struct		s_camera
{
	t_vector		cord;
	t_vector		ori;
	unsigned int	fov;
}					t_camera;

typedef struct		s_light
{
	t_vector		cord;
	double			ratio;
	t_rgb			color;
}					t_light;

typedef struct		s_sphere
{
	t_vector		cord;
	double			radius;
	t_rgb			color;
}					t_sphere;

typedef struct		s_plane
{
	t_vector		cord;
	t_vector		ori;
	t_rgb			color;
}					t_plane;

typedef struct		s_square
{
	t_vector		cord;
	t_vector		ori;
	double			height;
	t_rgb			color;
}					t_square;

typedef struct		s_cylinder
{
	t_vector		cord;
	t_vector		ori;
	double			diameter;
	double			height;
	t_rgb			color;
}					t_cylinder;

typedef struct		s_triangle
{
	t_vector		cord1;
	t_vector		cord2;
	t_vector		cord3;
	t_rgb			color;
}					t_triangle;

typedef struct		s_scene
{
	char			*line;
	char			*gnl;
	t_reso			reso;
	t_amli			amli;
	t_list			*camera;
	t_list			*light;
	t_list			*sphere;
	t_list			*plane;
	t_list			*square;
	t_list			*cylinder;
	t_list			*triangle;
}					t_scene;

#endif

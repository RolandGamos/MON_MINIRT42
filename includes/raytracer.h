/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:14:56 by lweglarz          #+#    #+#             */
/*   Updated: 2021/03/16 20:17:11 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACER_H
# define RAYTRACER_H

# include "minirt.h"

typedef struct	s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_img_data	img;
	t_scene		*scene;
	t_list		*camera_list;
	int			nb_cam;
}				t_mlx;

void	init_mlx_window(t_mlx *mlx_session, t_scene *scene);
void	init_mlx_image(t_mlx *mlx_session, t_scene *scene);
int		cam_hook(int keycode, t_mlx *mlx_session);
void	ray_tracer(t_scene *scene);
void	ray_init(t_ray *ray);
t_rgb	trace_ray(t_ray ray, t_scene *scene);
void	init_camera(t_ray *ray, t_camera *camera, t_px px, t_scene *scene);
void	keys(t_mlx mlx_session);

t_frgb	compute_light(t_vector ray_pos, t_vector normal, t_scene *scene, void *obj);

void	raytosphere(t_ray *ray, t_scene *scene);
double	sphere_intersec_equation(t_ray *ray, t_sphere *sphere, double *t);

void	raytoplane(t_ray *ray, t_scene *scene);
double	plane_intersec_equation(t_ray *ray, t_plane *plane);

void	raytotriangle(t_ray *ray, t_scene *scene);
double	triangle_intersec_equation(t_ray *ray, t_triangle *triangle, t_vector *normal);

void	raytosquare(t_ray *ray, t_scene *scene);
double	square_intersec_equation(t_ray *ray, t_square *square);

void	raytocylinder(t_ray *ray, t_scene *scene);
double	cylinder_intersec_equation(t_ray *ray, t_cylinder *cylinder);

int		sphere_intersec(t_scene scene, t_ray *ray);
int		triangle_intersec(t_scene scene, t_ray *ray);
int		plane_intersec(t_scene scene, t_ray *ray);
int		square_intersec(t_scene scene, t_ray *ray);

#endif

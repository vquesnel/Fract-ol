/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 13:29:40 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/09 14:31:33 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_env *env)
{
	long double		z_r;
	long double		z_i;
	int				i;
	int				x;
	int				y;
	long double		tmp;
	int				color;

	x = 0;
	while (x < X_SIZE)
	{
		y = 0;
		while (y < Y_SIZE)
		{
			z_r = (x - X_SIZE / 2) / (env->param->zoom + X1J);
			z_i = (y - Y_SIZE / 2) / (env->param->zoom + Y1J);
			i = -1;
			while ((z_r * z_r + z_i * z_i) < 4 && i++ < env->param->iter)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + env->param->c_r;
				z_i = 2 * z_i * tmp +  env->param->c_i;
			}
			if (i == env->param->iter)
				mlx_put_pixel_to_image(env, x + env->param->x_default, y + env->param->y_default, 255);
			else
			{
				color = i * env->param->color;
				mlx_put_pixel_to_image(env, x + env->param->x_default, y  +env->param->y_default, color);
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
}

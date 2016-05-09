/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_burningship.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:53:28 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/09 15:30:47 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void		init_burningship(t_env *env)
{
	long double		z_r;
	long double		z_i;
	long double		c_r;
	long double		c_i;
	int				i;
	int				x;
	int				y;
	long double		tmp;
	int				color;

	x = 0;
	while (x < X_SIZE)
	{
		y = -1;
		while (++y < Y_SIZE)
		{
			c_r = (x - X_SIZE / 3) / (env->param->zoom - 2.1);
			c_i = (y - Y_SIZE / 3) / (env->param->zoom - 1.2);
			z_r = 0;
			z_i = 0;
			i = -1;
			while ((z_r * z_r + z_i * z_i) < 4 && i++ < env->param->iter)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * fabsl(z_i * tmp) + c_i;
			}
			if ( i == env->param->iter)
				mlx_put_pixel_to_image(env, x + env->param->x_default, y + env->param->y_default, 255);
			else
			{
				color = i * env->param->color;
				mlx_put_pixel_to_image(env, x + env->param->x_default, y + env->param->y_default, color);
			}
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
}

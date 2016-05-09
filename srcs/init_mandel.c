/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mandel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 11:22:25 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/09 14:30:14 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mandel(t_env *env)
{
	long double		c_r;
	long double		c_i;
	long double		z_r;
	long double		z_i;
	int				i;
	int				x;
	int				y;
	long double		tmp;
	int				color;

	x = 0;
	while (x < Y_SIZE)
	{
		y = 0;
		while (y < X_SIZE)
		{
			c_r = (x - X_SIZE / 2) / (env->param->zoom + X1);
			c_i = (y - Y_SIZE / 2) / (env->param->zoom + Y1);
			z_r = 0;
			z_i = 0;
			i = 0;
			while ((z_r * z_r + z_i * z_i) < 4 && i < env->param->iter)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i == env->param->iter)
				mlx_put_pixel_to_image(env, x + env->param->x_default, y + env->param->y_default, 0xFFFFFF);
			else
			{
				color = i * env->param->color;
				mlx_put_pixel_to_image(env, x + env->param->x_default, y + env->param->y_default, color);
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
}

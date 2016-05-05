/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 13:29:40 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/05 15:01:33 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_julia(t_env *env)
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
	while (x < X_SIZE)
	{
		y = 0;
		while (y < Y_SIZE)
		{
			c_r = 0.285;
			c_i = 0.01;
			z_r = (x - X_SIZE / 2) / (env->param->zoom + X1J);
			z_i = (y - Y_SIZE / 2) / (env->param->zoom + Y1J);
			i = 0;
			while ((z_r * z_r + z_i * z_i) < 4 && i < env->param->iter)
			{
				tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				i++;
			}
			if (i == env->param->iter)
				mlx_put_pixel_to_image(env, x, y, 0);
			else
			{
				color = i * env->param->color / env->param->iter;
				mlx_put_pixel_to_image(env, x , y , color);
			}
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
}

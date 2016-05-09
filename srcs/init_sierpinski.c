/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sierpinski.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 12:05:12 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/09 14:50:02 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_sierpinski(t_env *env)
{
	int		y;
	int		x;
	int		color;

	y = -1;
	while (y++ < Y_SIZE)
	{
		x = -1;
		while (x++ < X_SIZE)
		{
			if (!((x) % 3 == 1 && (y) % 3 == 1) && !((x / 3) % 3 == 1 \
						&& (y / 3) % 3 == 1) && !((x / 9) % 3 == 1 && (y / 9) % 3 == 1)
					&& !((x / 27) % 3 == 1 && (y / 27) % 3 == 1) && !((x / 81) \
						% 3 == 1 && (y / 81) % 3 == 1))
			{
				color = env->param->color;
				mlx_put_pixel_to_image(env, x, y, color);
			}
		}
	}
	mlx_put_image_to_window(env->mlx, env->win, env->img->img, 0, 0);
}

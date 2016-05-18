/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:30:00 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/18 16:05:34 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_env *env)
{
	double	x_real;
	double	y_real;

	if (x > 0 && y > 0)
	{
		x_real = (x / env->p->zoom) + env->p->x1;
		y_real = (y / env->p->zoom) + env->p->y1;
		if (button == ZOOMIN)
		{
			env->p->zoom *= 1.1;
			env->p->x1 = x_real - (x / env->p->zoom);
			env->p->y1 = y_real - (y / env->p->zoom);
		}
		if (button == ZOOMOUT)
		{
			env->p->zoom /= 1.1;
			env->p->x1 = x_real - (x / env->p->zoom);
			env->p->y1 = y_real - (y / env->p->zoom);
		}
		if (button == LEFTCLICK)
			env->p->motion = (env->p->motion == 0) ? 1 : 0;
	}
	select_fractals(env);
	return (0);
}

int		motion_juliaandco(int x, int y, t_env *env)
{
	if (!ft_strcmp(env->name, "julia") || !ft_strcmp(env->name, "chameleon") \
			|| !ft_strcmp(env->name, "sword"))
	{
		if (env->p->motion % 2)
		{
			if (x > 0 && x < X_SIZE && y > 0 && y < Y_SIZE)
			{
				if (x < X_SIZE / 2 && y < Y_SIZE / 2)
					env->p->c_r += 0.05;
				if (x > X_SIZE / 2 && y < Y_SIZE / 2)
					env->p->c_r -= 0.05;
				if (x < X_SIZE / 2 && y > Y_SIZE / 2)
					env->p->c_i += 0.05;
				if (x > X_SIZE / 2 && y > Y_SIZE / 2)
					env->p->c_i -= 0.05;
			}
		}
		select_fractals(env);
	}
	return (0);
}

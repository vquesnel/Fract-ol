/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:30:00 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/11 17:17:00 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_env *env)
{
	double x_real;
	double	y_real;

	if (x > 0 && y > 0)
	{
		x_real = (x / env->p->zoom) + env->p->x1;
		y_real = (y / env->p->zoom) + env->p->y1;
		if ( button == 4)
		{
			env->p->zoom *= 1.1;
			env->p->x1 = x_real - (x / env->p->zoom);
			env->p->y1 = y_real - (y / env->p->zoom);
		}
		if (button == 5)
		{
			env->p->zoom /= 1.1;
			env->p->x1 = x_real - (x / env->p->zoom);
			env->p->y1 = y_real - (y / env->p->zoom);
		}
	}
	mlx_clear_window(env->mlx, env->win);
	select_fractals(env);
	return (0);
}

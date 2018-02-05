/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 15:30:00 by vquesnel          #+#    #+#             */
/*   Updated: 2018/02/05 17:22:14 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_env *env)
{
	if ((x > 0 && x < X_SIZE) && (y > 0 && y < Y_SIZE))
	{
		env->p->x_real = (x / env->p->zoom) + env->p->x1;
		env->p->y_real = (y / env->p->zoom) + env->p->y1;
		if (button == ZOOMIN)
			env->p->zoom *= 1.1;
		if (button == ZOOMOUT)
			env->p->zoom /= 1.1;
		env->p->x1 = env->p->x_real - (x / env->p->zoom);
		env->p->y1 = env->p->y_real - (y / env->p->zoom);
		if (button == LEFTCLICK)
			env->p->motion = (env->p->motion == 0) ? 1 : 0;
	}
	return (0);
}

int		motion_juliaandco(int x, int y, t_env *env)
{
	if ((x > 0 && x < X_SIZE) && (y > 0 && y < Y_SIZE))
	{
		if (!ft_strcmp(env->name, "julia") || !ft_strcmp(env->name, "chameleon")
			|| !ft_strcmp(env->name, "sword") || !ft_strcmp(env->name, "test"))
		{
			if (env->p->motion % 2)
			{
				if (x > env->p->x)
					env->p->c_i += 0.05;
				else if (x < env->p->x)
					env->p->c_i -= 0.05;
				if (y > env->p->y)
					env->p->c_r += 0.05;
				else if (y < env->p->y)
					env->p->c_r -= 0.05;
			}
		}
		env->p->x = x;
		env->p->y = y;
	}
	return (0);
}

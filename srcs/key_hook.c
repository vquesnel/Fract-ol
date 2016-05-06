/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:20:52 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/06 17:53:29 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_funct(int keycode, t_env *env)
{
	t_param		hook;

	if (env->mlx == NULL)
		return (0);
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	hook.zoom = env->param->zoom;
	hook.iter = env->param->iter;
	hook.x_default = env->param->x_default;
	hook.y_default = env->param->y_default;
	hook.color = env->param->color;
	hook.c_r = env->param->c_r;
	hook.c_i = env->param->c_i;
	if (keycode == MORE_ITER || keycode == LESS_ITER)
		iter(keycode, env, hook);
	if (keycode == MORE_COLOR || keycode == LESS_COLOR)
		color(keycode, env, hook);
	if (keycode == 18 | keycode == 19 || keycode == 20 || keycode == 21)
		parameter(keycode, env, hook);
	if (keycode == LEFT || keycode == RIGHT || keycode == UP\
	|| keycode == DOWN)
		moove(keycode, env, hook);
	return (0);
}

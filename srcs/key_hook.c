/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:20:52 by vquesnel          #+#    #+#             */
/*   Updated: 2018/02/05 17:08:35 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	modify_moove(t_env *env)
{
	static double	i = 0.2;

	if (env->p->zoom <= 100)
		i = 0.2;
	if (env->p->zoom > 100 && env->p->zoom <= 1000)
		i = 0.02;
	if (env->p->zoom > 1000 && env->p->zoom <= 10000)
		i = 0.002;
	if (env->p->zoom > 10000 && env->p->zoom <= 100000)
		i = 0.0002;
	if (env->p->zoom > 100000)
		i = 0.00002;
	i *= 4;
	return (i);
}

void			moove(int keycode, t_env *env)
{
	double	i;

	i = modify_moove(env);
	if (keycode == LEFT)
		env->p->x1 += i;
	else if (keycode == RIGHT)
		env->p->x1 -= i;
	else if (keycode == DOWN)
		env->p->y1 += i;
	else if (keycode == UP)
		env->p->y1 -= i;
}

static void		board_zoom(int keycode, t_env *env)
{
	env->p->x_real = (env->p->x / env->p->zoom) + env->p->x1;
	env->p->y_real = (env->p->y / env->p->zoom) + env->p->y1;
	if (keycode == ZOOMUP)
		env->p->zoom *= 1.1;
	if (keycode == ZOOMDOWN)
		env->p->zoom /= 1.1;
	env->p->x1 = env->p->x_real - (env->p->x / env->p->zoom);
	env->p->y1 = env->p->y_real - (env->p->y / env->p->zoom);
}

int				key_funct(int keycode, t_env *env)
{
	if (env->mlx == NULL)
		return (0);
	if (keycode == ESC)
		exit(EXIT_SUCCESS);
	if (keycode == MORE_ITER || keycode == LESS_ITER)
		iter(keycode, env);
	if (keycode == MORE_COLOR || keycode == LESS_COLOR)
		color(keycode, env);
	if (keycode == LEFT || keycode == RIGHT || keycode == UP\
			|| keycode == DOWN)
		moove(keycode, env);
	if (keycode == T1 || keycode == T2 || keycode == T3 || keycode == T4 || \
			keycode == T5)
		theme(keycode, env);
	if (keycode == ORIGIN)
		origin(keycode, env);
	if (keycode == ZOOMUP || keycode == ZOOMDOWN)
		board_zoom(keycode, env);
	return (0);
}

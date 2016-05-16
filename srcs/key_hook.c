/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 14:20:52 by vquesnel          #+#    #+#             */
/*   Updated: 2016/05/17 00:13:28 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double	modify_moove(t_env *env)
{
	static double i = 0.2;

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
	return (i);
}

void	moove(int keycode, t_env *env)
{
	double i;

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

int		key_funct(int keycode, t_env *env)
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
	if (keycode == SPACE)
		menu(env);
	mlx_clear_window(env->mlx, env->win);
	select_fractals(env);
	return (0);
}
